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
			NumberExpressionSyntaxNodeToken,
			BinaryExpressionSyntaxNodeToken
		};
		class ISyntaxNode;
		using ISyntaxNodePtr = std::shared_ptr<ISyntaxNode>;

		class ISyntaxNode
		{

		public:

			virtual SyntaxKind GetKind() = 0;

			virtual vector<ISyntaxNodePtr> GetChildren() const = 0;

			virtual bool operator==(const ISyntaxNode& other) const {
				return true;
			}
		};

		class SyntaxToken;
		using SyntaxTokenPtr = shared_ptr<SyntaxToken>;
		class SyntaxToken : public ISyntaxNode
		{
		private:
			SyntaxKind m_syntaxKind;
			int m_position;
			string m_text;

		public:
			SyntaxToken(SyntaxKind kind, int position, string text) :
				m_syntaxKind(kind), m_position(position), m_text(text)
			{

			};

			SyntaxKind GetKind()
			{
				return m_syntaxKind;
			}

			vector<ISyntaxNodePtr> GetChildren()const override
			{
				return vector<ISyntaxNodePtr>{};
			}

			bool operator==(const ISyntaxNode& baseClassSyntaxNode) const override
			{
				if (const SyntaxToken* syntaxToken = static_cast<const SyntaxToken*>(&baseClassSyntaxNode))
				{
					if (m_syntaxKind == syntaxToken->m_syntaxKind &&
						m_position == syntaxToken->m_position &&
						m_text == syntaxToken->m_text)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				return false;
			}

		};
			using SyntaxTokenList = vector<SyntaxTokenPtr>;
	}
}
#endif // !TDD_SYNTAXNODE_SYNTAXTOKEN_HPP
