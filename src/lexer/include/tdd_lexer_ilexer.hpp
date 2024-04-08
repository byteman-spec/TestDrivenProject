/*################################################################################################
Interface for lexer created 																	##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Interface for lexer				       			    ##
#################################################################################################*/
#ifndef TDD_LEXER_ILEXER_HPP
#define	TDD_LEXER_ILEXER_HPP
#include <string>
#include <vector>

using namespace std;

namespace TDD {

	namespace Lexer {

		class SyntaxToken;
		using SyntaxTokenList = vector<SyntaxToken>;

		class ILexer
		{
		public:
			virtual SyntaxTokenList Init()
			{
				SyntaxTokenList emptyList{};
				return emptyList;
			};

		};
	}
}
#endif // !TDD_LEXER_ILEXER_HPP
