/*################################################################################################
Interface for dbclient created for GtestMocking													##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Interface for dbclient created for GtestMocking     ##
#################################################################################################*/
#ifndef TDD_DBCLIENT_IDBCLIENT_HPP
#define	TDD_DBCLIENT_IDBCLIENT_HPP
#include <string>

using namespace std;

namespace TDD {

	namespace DBCLIENT {

		class IDbClient
		{
		public:
			virtual bool login(string username, string password) 
			{
				return true;
			};
			virtual bool logout(string username)
			{
				return true;
			}
			virtual int checkhealth()
			{
				return 0;
			}
		};
	}
}
#endif // !TDD_DBCLIENT_IDBCLIENT_HPP
