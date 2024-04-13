/*################################################################################################
Interface for lexer created 																	##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Interface for lexer				       			    ##
#################################################################################################*/
#ifndef TDD_PRINTER_IPRINTER_HPP
#define	TDD_PRINTER_IPRINTER_HPP
#include <string>
#include <vector>
#include <memory>
#include "../../parser/include/tdd_parser_iparser.hpp"

using namespace std;
using namespace TDD::Parser;

namespace TDD {

	namespace Printer {
		
		class IPrinter
		{
		public:

			virtual const char* PrintTree()
			{
				return "";
			}
		};
	}
}
#endif // !TDD_PRINTER_IPRINTER_HPP
