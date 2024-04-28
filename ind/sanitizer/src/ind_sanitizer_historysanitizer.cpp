/*################################################################################################
## Implementation class for Lexer																##
## 																								##
## HISTORY																						##
## DATE						#USERNAME		#DESC												##
## 08-Apr-2024				byteman-spec	Implementation for lexer				       		##
## 14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#include "include/ind_sanitizer_historysanitizer.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <iostream>
#include "config/config.h"


using namespace std;
using namespace IND;
using namespace IND::SANITIZER;

#define EOF_MARK 0


//New Comment
// 
// 
// 
//-----------------Static Functions---------------------
static string getFileExtenstion(const string& diffText);
static string getValidFileName(const string& diffText);
static string getValidFilePath(const string& filePath);
static bool startsWith(const string& inputString, const string& substr);
//-----------------Function Definitions-----------------

HistorySanitizer::HistorySanitizer(char* fileString)
{
	string logFilePath = HISTORY_SANITIZER_DIR;
	logFilePath += "/sanityLog.txt";
	char* logFilePathChar = new char[logFilePath.size()];
	strcpy(logFilePathChar, logFilePath.c_str());
	m_logFile = make_shared<fstream>(logFilePathChar, std::ios::out | std::ios::trunc);
	if (!m_logFile->is_open())
	{
		cout << "Error creating log file at " << m_logFile << endl;
	}

	m_filePath = fileString;
	m_file = make_shared<fstream>(m_filePath);
	if (!m_file->is_open())
	{
		*m_logFile.get() << "Error opening file at " << m_filePath << endl;
	}
	m_invalidFiles = {};
	m_curLine = "";
	m_parentFile = "";
	m_historyAdded = false;

}

bool HistorySanitizer::IsValidHistoryLine()
{
	return !startsWith(m_curLine, "+++ b/");
	
	
}

bool HistorySanitizer::SanitizeLine()
{
	if (!m_curLine.empty())
	{
		m_historyAdded = true;
		if (startsWith(m_curLine,"-"))
		{
			m_invalidFiles.emplace_back(m_parentFile);
			return false;
		}
		//We are not checking if there have been multiple historical editions
		//per push as one push might be a work spanning accross days of efforts.
	}
	return true;
}

int HistorySanitizer::GetNextLine()
{
	if (getline(*m_file.get(), m_curLine))
	{
		return m_curLine.size();
	}
	else return EOF_MARK;
}

bool HistorySanitizer::IsNewParentFile()
{
	return !getValidFileName(m_curLine).empty();
}


bool HistorySanitizer::Sanitize() 
{
	//create a unique file pointer and open and store the file in that 
	//while constructing. henceforth check if m_fileptr is null or not
	
	if (m_file->is_open())
	{
		while (!m_file->eof()) { // Read each line from the file
		// Process the line here, for example, you can print it
			GetNextLine();
			if (IsNewParentFile())
			{
				if (m_historyAdded || m_parentFile.empty())
				{
					m_parentFile = getValidFileName(m_curLine);
					m_historyAdded = false;
					Sanitize();
				}
				else
				{
					*m_logFile.get() << "Warning :: Missing history event in :: " << m_parentFile << endl;
					m_invalidFiles.emplace_back(m_parentFile);
					m_parentFile = getValidFileName(m_curLine);
					Sanitize();
				}
			}
			else
			{
				if (IsValidHistoryLine() && !SanitizeLine())
				{
					*m_logFile.get() << "Warning :: Invalid history event in :: " << m_parentFile << endl;
					*m_logFile.get() << "[HistoryEvent]::" << m_curLine << endl;
				}
			}
		}
		if (m_file->eof())
		{
			if (!m_historyAdded)
			{
				if (std::find(m_invalidFiles.begin(), m_invalidFiles.end(), m_parentFile) == m_invalidFiles.end())
				{
					*m_logFile.get() << "Warning :: Missing history event in :: " << m_parentFile << endl;
					m_invalidFiles.emplace_back(m_parentFile);
					return m_invalidFiles.empty();
				}
			}
		}
	}
	return m_invalidFiles.empty();
}


vector<string> HistorySanitizer::GetInvalidFileList() const
{
	return m_invalidFiles;
}

static string getLastSubstrAfter(const string& plaintext, const string& substr)
{
	string result = "";
	auto seperator = plaintext.rfind(substr);
	if (seperator != string::npos)
	{
		auto x = plaintext.size();
		int seperatorIndex = plaintext.size() - (seperator + substr.length());
		result = plaintext.substr(seperator + substr.length(), seperatorIndex);
	}
	return result;
}

static string getFileExtenstion(const string& diffText)
{
	return getLastSubstrAfter(diffText,".");
}

static string getValidFileName(const string &diffText)
{
	auto fileExt = getFileExtenstion(diffText);
	if (strcmp(fileExt.c_str(), "cpp") == 0 ||
		strcmp(fileExt.c_str(), "hpp") == 0)
	{
		return getLastSubstrAfter(diffText, "+++ b/");
	}
	return "";
}

string getValidFilePath(const string& filePath)
{
#if PLATFORM == WNT
	//I though modifications might be needed for generating valid path for different OS
	// but CMAKE is generating them accordingly
	//Letting this code be here for the timebeing because setting PLATFORM might come in useful in the future
#else
	//No modification needed
#endif
	return filePath;
}

static bool startsWith(const string& inputString, const string& substr)
{
	return (!inputString.empty() && inputString.find(substr) == 0);
}