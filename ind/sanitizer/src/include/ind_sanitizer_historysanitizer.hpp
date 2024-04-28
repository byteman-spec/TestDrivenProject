/*################################################################################################
## Unit test for IDBClient																		##
## 																								##
## HISTORY																						##
## DATE						#USERNAME		#DESC												##
## 08-Apr-2024				byteman-spec	Unit test for IDBClient							    ##
## 14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#ifndef IND_SANITIZER_HISTORYSANITIZER_HPP
#define	IND_SANITIZER_HISTORYSANITIZER_HPP

#include "ind_sanitizer_isanitizer.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>
#include <fstream>

using namespace testing;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using namespace std;


namespace IND {

	namespace SANITIZER {

		class HistorySanitizer;
		using HistorySanitizerPtr = shared_ptr<HistorySanitizer>;

		using FilePtr = shared_ptr<fstream>;
		class HistorySanitizer : public ISanitizer {

			char* m_filePath;
			FilePtr m_file;
			FilePtr m_logFile;
			string m_curLine;
			string m_parentFile;
			vector<string> m_invalidFiles;
			int GetNextLine();
			bool SanitizeLine();
			bool IsNewParentFile();
		public:
			HistorySanitizer(char* filePath);

			bool Sanitize(vector<string>& invalidFiles)  override;
			vector<string> GetInvalidFileList() const override;
		};

	}
}


#endif // !IND_SANITIZER_HISTORYSANITIZER_HPP


