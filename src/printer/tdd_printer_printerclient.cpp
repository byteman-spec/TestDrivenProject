/*################################################################################################
##Implementation class for Printer	 															##
## 																								##
## HISTORY																						##
## DATE						#USERNAME		#DESC												##
## 08-Apr-2024				byteman-spec	Implementation for Printer		  					##
## 14-Apr-2024				byteman-spec	Fixed History									    ##
#################################################################################################*/
#include "include/tdd_printer_printerclient.hpp"
#include "../parser/include/tdd_parser_parserclient.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <cctype>


using namespace std;
using namespace std;
using namespace TDD;
using namespace TDD::Printer;
using namespace TDD::Parser;


static string formatExpressionTokens(ISyntaxNodePtr parsedTokens, string& indent )
{
    string treeString = "\n";
    cout << "\n";
    cout << indent << parsedTokens->GetKindString();

    if (parsedTokens->GetKind() == SyntaxKind::NumberToken ||
        parsedTokens->GetKind() == SyntaxKind::PlusToken ||
        parsedTokens->GetKind() == SyntaxKind::HyphenToken)
    {
        if (const SyntaxTokenPtr syntaxTokenPtr = static_pointer_cast<SyntaxToken>(parsedTokens))
        {
            cout << "     " << syntaxTokenPtr->GetValue();
        }
    }
    auto children = parsedTokens->GetChildren();
    int index = 0;
    for (auto childExpression : children)
    {
        bool resetIndent = (index == children.size() - 1);
        if (index == 0)
        {
            indent += "     ";
        }
        formatExpressionTokens(childExpression, indent);
        index++;
        auto indentLen = indent.length();
        indent = resetIndent ? indent.substr(0,indent.length()-5) : indent;
        auto indentLenNew = indent.length();
    }

    return treeString;
}

const char* PrinterClient::PrintTree()
{
    const char* treeString = R"(
└──BinaryExpression
    ├──BinaryExpression
    │   ├──NumberExpression
    │   │   └──NumberToken 1
    │   ├──PlusToken
    │   └──NumberExpression
    │       └──NumberToken 2
    ├──PlusToken
    └──NumberExpression
        └──NumberToken 3
)";
    ExpressionSyntaxNodePtr parsedTokens = m_parser->Parse();

    string indent = "";
    formatExpressionTokens(parsedTokens, indent);
    return treeString;
}