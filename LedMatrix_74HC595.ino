class Run{
	private:
	int DEL;
	int WIDTH;
	int HEIGHT;
		int rank[8] = {                        // конфигурация разрядов одного сектора (в данном случае 8 пикселей)
			0b11111110,	// 1
			0b11111101,	// 2
			0b11111011,	// 3
			0b11110111,	// 4
			0b11101111,	// 5
			0b11011111,	// 6
			0b10111111,	// 7
			0b01111111,	// 8
		};
		unsigned char library_leters [33][10] = // configuration library of the leters
		{
			{5,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{6,0b11111000,0b00010100,0b00010010,0b00010010,0b11111110,0b00000000,0b00000000,0b00000000,0b00000000},
			{6,0b11111110,0b10001010,0b10001010,0b10001010,0b01110000,0b00000000,0b00000000,0b00000000,0b00000000},
			{6,0b11111110,0b10010010,0b10010010,0b10010010,0b01101100,0b00000000,0b00000000,0b00000000,0b00000000},
			{5,0b11111110,0b00000010,0b00000010,0b00000010,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{5,0b11111110,0b00000010,0b00000010,0b00000011,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{6,0b11000000,0b01111000,0b01000100,0b01000010,0b01111110,0b11000000,0b00000000,0b00000000,0b00000000},
			{4,0b11111110,0b10010010,0b10010010,0b10010010,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{7,0b11000110,0b00101000,0b00010000,0b11111110,0b00010000,0b00101000,0b11000110,0b00000000,0b00000000},
			{5,0b01000100,0b10000010,0b10010010,0b10010010,0b01101100,0b00000000,0b00000000,0b00000000,0b00000000},
			{6,0b11111110,0b00100000,0b00010000,0b00001000,0b11111110,0b00000000,0b00000000,0b00000000,0b00000000},
			{2,0b11111010,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{4,0b00000001,0b11111100,0b00000001,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{6,0b11111110,0b00100000,0b00010001,0b00001000,0b11111110,0b00000000,0b00000000,0b00000000,0b00000000},
			{6,0b11111110,0b00010000,0b00101000,0b01000100,0b10000010,0b00000000,0b00000000,0b00000000,0b00000000},
			{6,0b11111000,0b00000100,0b00000010,0b00000010,0b11111110,0b00000000,0b00000000,0b00000000,0b00000000},
			{8,0b11111110,0b00001000,0b00010000,0b00100000,0b00010000,0b00001000,0b11111110,0b00000000,0b00000000},
			{6,0b11111110,0b00010000,0b00010000,0b00010000,0b11111110,0b00000000,0b00000000,0b00000000,0b00000000},
			{6,0b01111100,0b10000010,0b10000010,0b10000010,0b01111100,0b00000000,0b00000000,0b00000000,0b00000000},
			{6,0b11111110,0b00000010,0b00000010,0b00000010,0b11111110,0b00000000,0b00000000,0b00000000,0b00000000},
			{6,0b11111110,0b00100010,0b00100010,0b00100010,0b00111110,0b00000000,0b00000000,0b00000000,0b00000000},
			{5,0b11111110,0b10000010,0b10000010,0b10000010,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
			{6,0b00000010,0b00000010,0b11111110,0b00000010,0b00000010,0b00000000,0b00000000,0000000000,0b00000000},
			{6,0b00001110,0b10010000,0b10010000,0b10010000,0b11111110,0b00000000,0b00000000,0b00000000,0b00000000},
			{8,0b00111110,0b00100010,0b00100010,0b11111111,0b00100010,0b00100010,0b00111110,0b00000000,0b00000000},
			{8,0b11000110,0b00101000,0b00010000,0b00101000,0b11000110,0b00000000,0b00000000,0b00000000,0b00000000},
			{6,0b11111110,0b10000000,0b10000000,0b10000000,0b11111110,0b10000000,0b00000000,0b00000000,0b00000000},
			{6,0b00011110,0b00010000,0b00010000,0b00010000,0b11111110,0b00000000,0b00000000,0b00000000,0b00000000},
			{7,0b11111110,0b10000000,0b10000000,0b11111110,0b10000000,0b10000000,0b11111110,0b00000000,0b00000000},
			{8,0b11111110,0b10000000,0b10000000,0b11111110,0b10000000,0b10000000,0b11111110,0b10000000,0b00000000},
			{6,0b11111110,0b10001000,0b10001000,0b10001000,0b11111000,0b00000000,0b00000000,0b00000000,0b00000000},
			{8,0b11111110,0b00010000,0b11111110,0b10000010,0b10000010,0b10000010,0b11111110,0b00000000,0b00000000},
			{6,0b10011110,0b01010010,0b00110010,0b00010010,0b11111110,0b00000000,0b00000000,0b00000000,0b00000000}
		};
	unsigned long previousMillis;
	int latchPin;
	int clockPin;
	int dataPin ;
	int number_ranks;
	int count;
		unsigned char ** memory (unsigned char ** array, int n, int m);
		unsigned long holdup(unsigned long interval);
		void clear(void);
		void words(unsigned char out_string[]);
	public:
	Run(){
		DEL = 6;
		previousMillis = 0;
		number_ranks = 0;
		count = 0;
		WIDTH = 8;
		HEIGHT = 8;
		latchPin = 8;      //Пин подключен к ST_CP входу 74HC595
		clockPin = 12;	   //Пин подключен к SH_CP входу 74HC595
		dataPin =  11;	   //Пин подключен к DS    входу 74HC595
	}
		void _holdup_ms(unsigned long del);
		void ticker(int number_leter, unsigned char _user_string[]);
		void set(int _latchPin, int _clockPin, int _dataPin){
			pinMode(_latchPin, OUTPUT);
			pinMode(_clockPin, OUTPUT);
			pinMode(_dataPin, OUTPUT);
			latchPin =_latchPin;
			clockPin =_clockPin;
			dataPin = _dataPin;
		}
		~Run(){}
	};
	Run string;

/******************************/
/** пользовательские строки  **/
/******************************/
unsigned char user_string_1[] = {0,20,7,16,18,17,22,0,7,15,7,14,22,20,18,22,7,25,17,11,14,10,0};
unsigned char user_string_2[] = {0,20,7,16,18,17,22,0,4,18,6,10,17,17,10,14,11,3,0};


void setup() {
	string.set(8,12,11);
}
void loop() {
	string.ticker(sizeof(user_string_1), user_string_1);
	string._holdup_ms(1000);
	string.ticker(sizeof(user_string_2), user_string_2);
	string._holdup_ms(2000);

}
/********************************************/
/**          THE BASIC FUNCTIONS           **/
/********************************************/
unsigned char ** Run:: memory (unsigned char ** array, int n, int m)
{
	int i = 0;
	array = (unsigned char**)calloc(n,sizeof(unsigned char*));
	for (i = 0; i < n; i++)
	*(array + i) = (unsigned char*)calloc(m,sizeof(unsigned char));

	return array;
}
unsigned long Run:: holdup(unsigned long interval)
{
	unsigned long currentMillis = millis();
	unsigned long difrent = currentMillis - previousMillis ;
	(difrent >= interval) ? previousMillis = currentMillis : previousMillis ;
	return difrent;
}
void Run:: _holdup_ms(unsigned long del)
{
	while (1){ unsigned long var = holdup(del);
		if(var >= del)break;
	}
}
void Run:: clear(void)
{
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, MSBFIRST, 0b11111111);
	shiftOut(dataPin, clockPin, MSBFIRST, 0b00000000);
	digitalWrite(latchPin, HIGH);
}
void Run:: words(unsigned char out_string[]){
	int start, position;
	for (start = 0, position = WIDTH; start < number_ranks; start++, position++ )
	{
		for (count; count < DEL; count++){
			for (int i = start, j = 0; i < position; i++, j++)
			{
				digitalWrite(latchPin, LOW);
				shiftOut(dataPin, clockPin, MSBFIRST, rank[j]);
				shiftOut(dataPin, clockPin, MSBFIRST, out_string[i]);
				digitalWrite(latchPin, HIGH);
				_holdup_ms(2);
				clear();
			}
		} count = 0;
	}
}
void Run:: ticker(int number_leter, unsigned char _user_string[])
{
	unsigned char  *stringOut_1 = NULL;
	unsigned char **user_array  = NULL;
	user_array = memory(user_array, number_leter, HEIGHT + 2 );
	for (int i = 0; i < number_leter; i++)
	{   
		/** Если символа нет в библиотеке "library_leters[][]" пропускаем итерацию **/
		if(_user_string[i] < 0 || _user_string[i] > sizeof(library_leters)) continue;
		for(int j = 0; j < HEIGHT+2; j++){
			user_array[i][j] = library_leters[_user_string[i]][j];
		}
	}
	number_ranks = 0;
	for (int i = 0; i < number_leter; i++)
	{
		number_ranks = number_ranks + user_array[i][0];
	}
	/** выделение памяти под масссив конфигурациии разрядов **/
	stringOut_1 = (unsigned char*)calloc(number_ranks, sizeof(unsigned char*));
	/** создание массива конфигунации разрядов   **/
	int number = 0;
	for (int i = 0; i < number_leter; i++)
	{
		for(int j = 1; j < HEIGHT+2 ; j++)
		{
			number++;
			stringOut_1[number] = user_array[i][j];
			if(user_array[i][j] == 0 && user_array[i][1] != 0) break; // обрезаем нули минуя символ пробел
			else if(user_array[i][1] == 0b00000000 &&  j == 4) break; // определяем величину пробела изменяя " j "
		}
	}
	for (int i = 0; i < number_leter; i++){
		free (*(user_array + i));
	}
	free(user_array);
	words(stringOut_1);
	free(stringOut_1);
}


