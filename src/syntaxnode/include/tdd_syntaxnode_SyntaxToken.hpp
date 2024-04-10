/*################################################################################################
Header for lexer created 																		##
#HISTORY																						##
#DATE						#USERNAME		#DESC												##
#08-Apr-2024				byteman-spec	Header for lexer				       			    ##
#################################################################################################*/
#ifndef TDD_SYNTAXNODE_SYNTAXTOKEN_HPP
#define	TDD_SYNTAXNODE_SYNTAXTOKEN_HPP
#include <string>
#include <vector>
#include <memory>
using namespace std;

namespace TDD {

	namespace SyntaxNode {

		enum SyntaxKind {
			NumberToken,
			WhitespaceToken,
			PlusToken,
			HyphenToken,
			StarToken,
			EndOfFileToken,
			OpenParanthesisToken,
			CloseParanthesisToken,
			SlashToken,
			InvalidToken,
			SyntaxNodeToken,
			ExpressionSyntaxNodeToken,
			NumberExpressionSyntaxNodeToken,
			BinaryExpressionSyntaxNodeToken
		};
		class ISyntaxNode;
		using ISyntaxNodePtr = std::shared_ptr<ISyntaxNode>;

		class ISyntaxNode
		{

		public:

			virtual SyntaxKind GetKind()
			{
				return SyntaxKind::SyntaxNodeToken;
			}

			virtual vector<ISyntaxNodePtr> GetChildren() = 0;
		};

		class SyntaxToken;
		using SyntaxTokenPtr = shared_ptr<SyntaxToken>;
		class SyntaxToken : ISyntaxNode
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

			vector<ISyntaxNodePtr> GetChildren() override
			{
				return vector<ISyntaxNodePtr>{};
			}

			bool operator==(const SyntaxToken other) const {
				return m_syntaxKind == other.m_syntaxKind &&
					m_position == other.m_position &&
					m_text == other.m_text;
			}
		};

		using SyntaxTokenList = vector<SyntaxTokenPtr>;

	}
}
#endif // !TDD_SYNTAXNODE_SYNTAXTOKEN_HPP
