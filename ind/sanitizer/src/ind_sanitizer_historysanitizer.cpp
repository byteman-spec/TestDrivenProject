/*################################################################################################
## Implementation class for Lexer																##
## 																								##
## HISTORY																						##
## DATE						#USERNAME		#DESC												##
## 08-Apr-2024				byteman-spec	Implementation for lexer				       		##
## 14-Apr-2024				byteman-spec	Fixed History									    ##
## 28-Apr-2024				byteman-spec	Added new history to check Sanitizer			    ##
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

//-----------------Static Functions---------------------
static string getFileExtenstion(const string& diffText);
static string getValidFileName(const string& diffText);
static string getValidFilePath(const string& filePath);
static bool startsWith(const string& inputString, const string& substr);
//-----------------Function Definitions-----------------

HistorySanitizer::HistorySanitizer(char* fileString)
{
	m_filePath = fileString;
	m_file = make_shared<ifstream>(m_filePath);
	if (!m_file->is_open())
	{
		cout << "Error opening file at " << m_filePath<<endl;
	}
	m_invalidFiles = {};
	m_curLine = "";
	m_parentFile = "";

}


bool HistorySanitizer::SanitizeLine()
{
	if (!m_curLine.empty())
	{
		if (startsWith(m_curLine,"-"))
		{
			m_invalidFiles.emplace_back(m_parentFile);
			return false;
		}
		//We are not checking if there have been multiple historical editions
		//per push as one push might be a work spanning accross days of efforts.
		return true;
	}
}

int HistorySanitizer::GetNextLine()
{
	if (getline(*m_file.get(), m_curLine))
	{
		return m_curLine.size();
	}
	else return (int)eof;
}

bool HistorySanitizer::IsNewParentFile()
{
	return !getValidFileName(m_curLine).empty();
}


bool HistorySanitizer::Sanitize(vector<string>& invalidFiles) 
{
	//create a unique file pointer and open and store the file in that 
	//while constructing. henceforth check if m_fileptr is null or not
	
	if (m_file->is_open())
	{
		while (!m_file->eof()) { // Read each line from the file
		// Process the line here, for example, you can print it
			if (!IsNewParentFile())
			{
				GetNextLine();
			}
			m_parentFile = getValidFileName(m_curLine);
			if (!m_parentFile.empty())
			{
				if ((GetNextLine() != (int)eof))
				{
					//validate the next line
					//if invalid history event,add to list of invalid files
					//if valid history event, continue
					//history event will only be valid if it contains only 1 historical addition
					if (!SanitizeLine())
					{
						cout << "Warning :: Invalid history event in :: " << m_parentFile << endl;
						cout << "[HistoryEvent]::" << m_curLine << endl;
					}
				}
				int nextLineItr = 0;
				do
				{
					nextLineItr = GetNextLine();
					if (nextLineItr != (int)eof)
					{
						if (!IsNewParentFile())
						{
							SanitizeLine();
						}
					}
				} while (!IsNewParentFile() && !m_file->eof());


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
		return getLastSubstrAfter(diffText, "\+\+\+ b/");
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
	return (inputString.find(substr) == 0);
}