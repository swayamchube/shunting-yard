// Shunting Yard Algorithm
// Input: Digits and Operators forming a sane expression in INFIX notation
// Output: Evaluation of expression

#include <bits/stdc++.h>

int main() {
	std::stack<char> output;
	std::stack<char> opstack;

	std::string s;
	std::cin >> s;
	int n = s.length();

	for (int i = 0; i < n; ++i) {
		char x = s[i];
		// If token is an operator
		if (x < 0x30 || x > 0x39) {
			switch(x) {
				case '*':
					opstack.push(x);
					break;
				case '/':
					opstack.push(x);
					break;
				case '+':
					while (!opstack.empty()) {
						char y = opstack.top();
						if (y == '*' || y == '/') {
							opstack.pop();
							output.push(y);
						} else break;
					}
					opstack.push(x);
					break;
				case '-':
					while (!opstack.empty()) {
						char y = opstack.top();
						if (y == '*' || y == '/') {
							opstack.pop();
							output.push(y);
						} else break;
					}
					opstack.push(x);
					break;
				case '(':
					opstack.push(x);
					break;
				case ')':
					while (opstack.top() != '(') {
						output.push(opstack.top());
						opstack.pop();
					}
					opstack.pop();
					break;
			}
		} else { output.push(x); }
	}

	while (!opstack.empty()) {
		output.push(opstack.top());
		opstack.pop();
	}

	std::stack<char> postfix;

	while (!output.empty()) {
		postfix.push(output.top());
		output.pop();
	}

	// We now have postfix representation 
	std::stack<int> answer;

	while (!postfix.empty()) {
		char x = postfix.top();
		postfix.pop();

		if (x >= 0x30 && x <= 0x39) answer.push(x - 0x30);
		else {
			int a = answer.top();
			answer.pop();
			int b = answer.top();
			answer.pop();
			switch (x) {
				case '*':
					answer.push(a * b);
					break;
				case '/':
					answer.push(b / a);
					break;
				case '+':
					answer.push(a + b);
					break;
				case '-':
					answer.push(a - b);
					break;
				default:
					break;
			}
		}
	}

	std::cout << answer.top() << "\n";
}
