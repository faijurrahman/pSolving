template <class Type>
const Type & findMax( const vector<Type> & data )
{
	int maxIndex = 0;
	for( int i = 1; i < data.size( ); i++ )
		if( data[maxIndex] < data[i] )
			maxIndex = i;
	return data[maxIndex];
}