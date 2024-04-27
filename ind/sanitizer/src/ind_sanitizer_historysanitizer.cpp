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


using namespace std;
using namespace IND;
using namespace IND::SANITIZER;

HistorySanitizer::HistorySanitizer(char* fileString)
{
	m_filePath = fileString;
}


bool HistorySanitizer::Sanitize(vector<string>& invalidFiles) const
{
	//create a unique file pointer and open and store the file in that 
	//while constructing. henceforth check if m_fileptr is null or not

	return false;
}
