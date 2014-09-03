template <class Type>
void multiInput(vector<Type>& input)
{
	Type temp;
	while(cin >> temp) input.push_back(temp); //Press Ctrl+Z (EOF) to break
	for( int i = 0; i < input.size(); i++ ) cout << input[i] << endl;
}