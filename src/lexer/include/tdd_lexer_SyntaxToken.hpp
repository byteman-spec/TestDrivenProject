/*################################################################################################
Header for lexer created 																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
#################################################################################################*/
#ifndef TDD_LEXER_SYNTAXTOKEN_HPP
#define	TDD_LEXER_SYNTAXTOKEN_HPP
#include <string>
#include <vector>

using namespace std;

namespace TDD {

	namespace Lexer {

		enum SyntaxKind {
			NumberToken,
			WhitespaceToken,
			PlusToken,
			MulToken,
			EndOfFileToken,
			InvalidToken
		};

		class SyntaxToken 
		{
		private :
			SyntaxKind m_syntaxKind;
			int m_position;
			string m_text;

		public:
			SyntaxToken(SyntaxKind kind, int position, string text) : 
				m_syntaxKind( kind ), m_position( position ), m_text( text )
			{

			};

			SyntaxKind GetKind()
			{
				return m_syntaxKind;
			}

			bool operator==(const SyntaxToken& other) const {
				return m_syntaxKind == other.m_syntaxKind &&
					m_position == other.m_position &&
					m_text == other.m_text;
			}
		};
	}
}
#endif // !TDD_LEXER_SYNTAXTOKEN_HPP
