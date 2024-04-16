/*################################################################################################
Header for lexer created 																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
#################################################################################################*/
#ifndef TDD_PRINTERUNITTEST_PRINTERCLIENTMOCK_HPP
#define	TDD_PRINTERUNITTEST_PRINTERCLIENTMOCK_HPP
#include <string>
#include <vector>
#include "../../../../src/printer/include/tdd_printer_iprinter.hpp"
#include "../../../../src/parser/include/tdd_parser_iparser.hpp"
#include <gmock/gmock.h>

using namespace std;
using namespace TDD::Parser;
using namespace TDD::Printer;

namespace TDD {

	namespace PrinterUnitTest {

		class PrinterClientMock;
		using PrinterClientMockPtr = shared_ptr<PrinterClientMock>;
		class PrinterClientMock : IPrinter
		{
		public:
			MOCK_METHOD(const char*, PrintTree, (), (override));
		};
	}
}
#endif // !TDD_PRINTERUNITTEST_PRINTERCLIENTMOCK_HPP
