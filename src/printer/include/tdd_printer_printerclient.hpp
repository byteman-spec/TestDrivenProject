/*################################################################################################
## Header class for Printer																		##
## 																								##
## HISTORY																						##
## DATE						#USERNAME		#DESC												##
## 08-Apr-2024				byteman-spec	Header for Printer			      					##
## 14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#ifndef TDD_PRINTER_PRINTERCLIENT_HPP
#define	TDD_PRINTER_PRINTERCLIENT_HPP
#include <string>
#include <vector>
#include "tdd_printer_iprinter.hpp"
//#include "../../syntaxnode/include/tdd_syntaxnode_SyntaxToken.hpp"

using namespace std;
using namespace TDD::Printer;

namespace TDD {

	namespace Printer {
		class PrinterClient;
		using PrinterClientPtr = shared_ptr<PrinterClient>;

		class PrinterClient : public IPrinter
		{
		private :
			IParserPtr m_parser;
			char* treeString;
		public:
			PrinterClient(IParserPtr parserPtr) :m_parser(parserPtr)
			{

			};
			const char* PrintTree() override;
		};
	}
}
#endif // !TDD_PRINTER_PRINTERCLIENT_HPP
