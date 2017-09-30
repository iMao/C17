#include "study_stl.h"


//----------------------------------------------������������ ������� array<>-------------------------------------------------------
void test_array()
{
	//������� ���� ������� array<>
	std::array<char, 12> word{};
	strcpy(word.data(), "Hello world");

	word.at(11) = '\0';

	cout << endl << word.data() << endl;

	
	//������������ �������������
	std::array<int, 10> a{ 0,1,2,3,4,5,6,7,8,9 };				//������������� ��� ���������� ������� �������������

	std::array<int, 10> b{};									//������������� ���� ��������� ����� 	
		
	std::array<int, 10> c(a);									//����� �������� ������������ �����������

	std::array<int, 10> d = std::move(b);						//����� ������������ �����������

	b.fill(5);													//��������� ��� �������� ������� ��������� 5	

	print_array(b);
	print_array(c);
	print_array(word);

	std::array<int, 3> zero;									//�������� �����		
	print_array(zero);

	std::array<int, 5> half_zero{ 1,2 };						//0-� � 1-� �������� 1 � 2 ��������� - 0
	print_array(half_zero);


	std::array<int, 10> a_{ 0,1,2,3,4,5,6,7,8,9 };				//����� ������� �
	compare_arrays(a, a_);

	std::array<int, 10> b_{ 1,2,3,4,5,6,7,8,9,10 };				//
	compare_arrays(b, b_);


	//��������� ���������� ��� ������ �� ������� �������
	try {
		for (int i = 0; i < 12; i++)
			cout << endl << "a[" << i << "] = " << a.at(i);
	}
	catch (std::exception& e)
	{
		std::cerr <<endl<< "EXCEPTION " << e.what() << endl;
	}


	//������������ ��������� �����������
	std::array<int, 5> s{ 9,9,9,9,9 };
	std::array<int, 5> h = std::move(s);							//���������� ������� ����������� ��������� �������

	s[0] = 0;
	s[1] = 1;

	print_array(s);
	print_array(h);

	

	//������ � ���������
	std::array<Object<int, 5>, 5> matrix;
	for (auto& ar : matrix)
		ar.print();


	//������������� �������� ������������� std::initializer_list<> ����������
	std::initializer_list<int> lst{2,5,7,1,8,9};


	//���������� ���������� STL
	std::array<float, 5> flt{ 3.0f, 3.1f, 3.2f };
	
	std::array<float, 5> transform_flt{};

	float sum = std::accumulate(flt.begin(), flt.end(), static_cast<float>(0));
	cout << endl << "sum = " << sum << endl;

	std::transform(flt.begin(), flt.end(), transform_flt.begin(), std::negate<float>());					//���������� ������� � ������ ������
	print_array(flt);
	print_array(transform_flt);

	std::transform(flt.begin(), flt.end(), flt.begin(), [](float& a)->float { return a *= 2.0f; } );			//���������� ������� � ��� �� ������
	print_array(flt);


	//������ ���������� � �������

	cout << endl << ( (flt.empty() == true) ? " array is empty" : " array full") << endl;
	cout << endl << " flt array max size = " << flt.max_size() << endl;
	cout << endl << " half_zero array max size = " << half_zero.max_size() << endl;


	cout << endl << "get front element = " << flt.front() << endl;
	cout << endl << "get back element = " << flt.back() << endl;
}

//---------------------------------------------������������ std::pair<T1,T2>p------------------------------------------------------
void test_pairs()
{
	//�������� ���
	std::pair<int, string> p1;														//������ ����
	cout << endl <<"p1 = "<< p1 << endl;

	std::pair<int, string>  p2 = std::make_pair(0, string("Pair"));					//������������� std::make_pair()
	cout << endl << "p2 = " << p2 << endl;

	std::pair<int, string> p3(p2);													//������������� ����������� ������������
	cout << endl << "p3 = " << p3 << endl;

	std::pair<int, string> p4{ 5, "five" };											//������������� ������ �������������
	cout << endl << "p4 = " << p4 << endl;

	std::pair<int, string> p5 = std::move(p4);										//������������� ������������� ������������
	cout << endl << "p5 = std::move(p4) "<< p5 << endl;
	cout << endl << "p4 = " << p4 << endl;

	std::pair<int, string> p6{};													//������ ������ �������������
	cout << endl << "p6 = " << p6 << endl;
	
	auto p7 = std::make_pair('Q', '@');												//�������� ���� std::pair<char, char>		
	cout << endl << "p7 = " << p7 << endl;

	auto p8 = std::make_pair("D", "S");												//�������� ���� std::pair<const char*, const char*>			
	cout << endl << "p8 = " << p8 << endl;

	std::pair<int, float> p9(3, 2.71f);
	cout << endl << "p9 = " << p9 << endl;




	//����� ������
	cout << endl << "exchange pairs" << endl;

	std::pair<int, char> a1(9, 'Y');
	std::pair<int, char> a2(3, 'R');

	cout << endl << "a1 = " << a1 << endl;
	cout << endl << "a2 = " << a2 << endl;

	std::swap(a1, a2);																//����� ������	

	cout << endl << "a1 = " << a1 << endl;
	cout << endl << "a2 = " << a2 << endl;


	string f{ "first" };
	string s{ "second" };
	
	std::pair<string, string> a3 = std::make_pair(std::move(f), std::move(s));		//������������� ��������� ����������� � std::make_pair( std::move(), std::move() )

	cout << endl << "a3 = " << a3 << endl;
	cout << endl << "f = " << f << endl;
	cout << endl << "s = " << s << endl;

	int i = 0;

	auto a4 = std::make_pair(std::ref(i), std::ref(i));								//������������� ��������� ������ std::ref()		
	cout << endl << "a4 = " << a4 << endl;

	++a4.first;
	++a4.second;

	cout << endl << "a4 = " << a4 << endl;

	std::pair<char, double> a5{ 'Z', 4.789 };

	cout << endl <<"std::get<0>(a5) = "<<std::get<0>(a5)<<endl;
	cout << endl <<"std::get<1>(a5) = "<<std::get<1>(a5)<<endl;


	auto res = solve_equation(1.4f, 7.0f, 2.0f);
	cout << endl << "  result " << res << endl;


}

//---------------------------------------------������������ �������� std::tuple<T1,T2,...Tn> t-------------------------------------
void test_tuples()
{
	auto lam = [&](std::tuple<int, float, string>& t) {

		cout << endl << "tuple<int, float, string> t -> " << "[" << std::get<0>(t) <<","<< std::get<1>(t) << "," << std::get<2>(t) << "]";

	};

	//�������� �������
	std::tuple<int, float, string> t0;									//������ �� 3-� ��������� � �������������� �������������� �� ���������												
	std::tuple<int, float, string> t1(5, 4.2f, "string");				//������ �� 3-� ��������� � �������������� ��������� ����������
	std::tuple<int, float, string> t2{ 3,2.71f,"Hello" };				//������ �� 3-� ��������� � �������������� ������� �������������
	std::tuple<int, float, string> t3(t1);								//������ �� 3-� ��������� � �������������� ������������� �����������
	auto t4 = std::make_tuple(0, 0.1f, string("auto"));					//�������� ������� � ������� ����� �� ���������������� ��������

	lam(t0);
	lam(t1);
	lam(t2);
	lam(t3);
	lam(t4);

	int i = 33;	
	float f = 0.9f;
	string s("*******");

	auto t5 = std::make_tuple(std::ref(i), std::ref(f), std::ref(s));		//�������� ������� ������ � ������� std::make_tuple()
	auto t6 = std::tie(i, f, s);											//�������� ������� ������ � ������� std::tie()


	cout << endl << "tuple<int&, float&, string&> t5 -> " << "[" << std::get<0>(t5) << "," << std::get<1>(t5) << "," << std::get<2>(t5) << "]";
	cout << endl << "tuple<int&, float&, string&> t6 -> " << "[" << std::get<0>(t6) << "," << std::get<1>(t6) << "," << std::get<2>(t6) << "]";


	auto t7 = std::tuple_cat(t1, t2);										//�������� ������� �������� �� ���� ������

	cout << endl << "tuple<int, float, string, int, float, string> t7 -> " << "[" << std::get<0>(t7) << "," << std::get<1>(t7) << "," << std::get<2>(t7) << ","
	<< std::get<3>(t7) << "," << std::get<4>(t7) << "," << std::get<5>(t7) << "]"<<endl;

	std::pair<int, string> p0{ 9, std::string("pair") };
	std::tuple<int, string>t8(p0);											//�������� ������� ����� ������ ������������ ����������� ��� ������� std::pair<>

	//��������� ������������� �������
	typedef std::tuple<string, int, char, double, short, bool, long> long_tuple;

	cout << endl << "std::tuple_size<decltype(t2)>::value = " << std::tuple_size<decltype(t2)>::value << endl;
	cout << endl << "std::tuple<string, int, char, double, short, bool, long> " << std::tuple_size<long_tuple>::value << endl;
	cout << endl << "std::tuple<int,char> t " << std::tuple_size<std::tuple<int, char>>::value << endl;

	//�������� ��� �������� �������
	std::tuple_element<0, long_tuple>::type str("same element");
	cout << endl << str << endl;

	//��������� ������� ��� std::array<>
	cout << "std::tuple_size<std::array<string,5>>::value = " << std::tuple_size<std::array<string, 5>>::value << endl;
	
	std::tuple_element<0, std::array<int, 10>>::type a = 10;
	cout << "a = " << a << endl;

	std::array<string, 10> ar{"Nico","pico"};
	cout <<endl<<"std::get<0>(ar) = "<<std::get<0>(ar)<<endl;


	//std::pair<> ��� �������� ������ �������
	std::tuple<std::pair<int, string>, std::pair<char, float>> complex_t(std::make_pair(8,string("++++++++")), std::make_pair(1,1.12f));

	cout << endl << "internal pairs " << std::get<0>(complex_t) << "     " << std::get<1>(complex_t) << endl;

}

std::ostream & operator<<(std::ostream & ostr, Some& s)
{
	return ostr << "Some { " << s.getA() << ", " << s.getS() << " }" << endl;
}

//��������� ������������� ������� ��� ���� bool
template<>
void print_vector<bool>(std::vector<bool>& v)
{
	cout << endl;
	for (auto & e : v)
		cout << "bit = " << std::boolalpha << e << endl;
}

//---------------------------------------------������������ ���������� std::vector<>---------------------------------------
void test_vector()
{
	//������� �������� ���������� std::vector<>
	std::vector<int> vec0;										//�������� ������� ������� ��� ��������� ���� int
	std::vector<int> vec1(3);									//�������� ������� �� 3-� ��������� ������������������ �������������� �� ���������
	std::vector<int> vec2(3, 777);								//�������� ������� �� 3-� ��������� �� ���������� 777, 777, 777
	std::vector<int> vec3{1,0,35,89};							//�������� ������� ��� ������ ������ ������������� {3,4,5,6,7}

	std::vector<int> vec4(vec2);								//�������� ������� ��� ������ ������������ �����������		
	std::vector<int> vec5(std::move(vec3));						//�������� ������� ��� ������ ������������� ������������

	std::vector<int> vec6(vec2.begin(), vec2.end());            //�������� ������� �� ������ ��������� ������� ������� 

	std::initializer_list<int> initList{1,2,3,4,5,6,7,8,9};		//������ �������������
	std::vector<int> vec7 = initList;							//�������� ������� ����� ���������� ������ �������������								

	std::vector<int> vec8 = vec7;								//�������� ������� ����� ����������� ������������
	std::vector<int> vec9 = std::move(vec8);					//�������� ������� ����� ������������� ������������


	//����� ���������� � �������
	print_vector_info(vec5);

	vec5.reserve(10);											//����������� ������ ������ ��� ������� ��� �������� 10 ���������

	print_vector_info(vec5);

	vec5.shrink_to_fit();										//��������� ������� �� ���������� ���������	

	print_vector_info(vec5);

	vector_empty_info(vec3);									//���������� ������������ ����������� �������� ������ vec3 - ������

	//������������ ���������
	std::vector<int> vec10 = initList;
	print_vector(vec10);

	vec10.assign({ 0,0,0 });									//assign - ��� ������ ����������, ��� ���� ��������� ��� ������� �������� �������	
	print_vector(vec10);

	vec10.assign(5, 7);
	print_vector(vec10);

	vec10.assign(vec2.begin(), vec2.end());
	print_vector(vec10);

	std::initializer_list<int> ilist{ 9,8,7,6,5,4,3,2,1 };
	vec10.assign(ilist);
	print_vector(vec10);


	//������ � ��������� �������
	vec10[0] = 0;												//������ � �������� ��� ������ [i]		
	vec10[8] = 0;
	print_vector(vec10);

	vec10.at(0) = -1;											//������ � �������� ��� ������ ������� at(i)	
	
	try {
		vec10.at(9) = -1;										//����� �� ������� ���������
	}
	catch (std::exception& e)
	{
		std::cerr << "EXCEPTION " << e.what() << endl;
	}
	print_vector(vec10);

	cout << endl << "front e = " << vec10.front() << " back e = " << vec10.back() << endl;

	//������������ ����������
	std::vector<int> ivec{7,5,3};
	test_iterators(ivec);


	//�������� ������� � �������� ��������� �������
	std::vector<int> int_vec;
	for (int i = 0; i < 5; ++i)
		int_vec.push_back(i);									//��������� � ����� ������� ��������

	print_vector(int_vec);
	
	int_vec.pop_back();											//������� � ����� ������� �������
	int_vec.pop_back();											//���

	print_vector(int_vec);

	std::vector<int>::iterator i = int_vec.begin();
	++i;
	int_vec.insert(i, 100);										//��������� ���� �������	
	print_vector(int_vec);

	i = int_vec.begin();
	++i;
	int_vec.insert(i, 2, 90);									//��������� 2 �������� 90
	print_vector(int_vec);

	int_vec.insert(int_vec.begin(), ivec.begin(), ivec.end());	//��������� �������� �������� �� ������� �������
	print_vector(int_vec);

	i = int_vec.begin();
	int_vec.insert(i, {0,1,0,1});
	print_vector(int_vec);


	//�������� emplace()
	std::vector<Some> vec_some;
	vec_some.push_back(Some(3,"Hello "));
	vec_some.push_back(Some(5,"Jack "));

	vec_some.emplace_back(5, "Nico ");
	vec_some.emplace(vec_some.begin() + 1, 0, "Pico");

	cout << endl;
	print_vector(vec_some);

	//�������� erase()
	vec_some.emplace_back(9, "Hero");
	vec_some.emplace_back(10, "Niger");
	vec_some.emplace_back(12, "Bigger");

	cout << endl;
	print_vector(vec_some);

	vec_some.erase(vec_some.end() - 1);
	
	cout << endl;
	print_vector(vec_some);

	vec_some.erase(vec_some.begin() + 1, vec_some.end());
	print_vector_info(vec_some);
	
	cout << endl;
	print_vector(vec_some);

	//�������� resize()
	std::vector<int> iv{ 9,9,9,9,9,9,9 };
	print_vector(iv);

	iv.resize(4);
	print_vector(iv);

	iv.resize(8);
	print_vector(iv);

	iv.resize(10, 5);
	print_vector(iv);

	iv.clear();
	iv.shrink_to_fit();
	print_vector_info(iv);


	//������������� ���������� std::vector<bool>
	std::vector<bool> flags;
	flags.push_back(true);
	flags.push_back(true);
	flags.push_back(false);
	flags.push_back(false);

	print_vector(flags);

	flags.flip();

	print_vector(flags);
	print_vector_info(flags);

	flags[0].flip();
	flags[1] = true;
	print_vector(flags);

	flags.pop_back();
	flags.insert(flags.begin(), 5, true);

	print_vector(flags);

}

//-------------------------------------������������ ���������� std::deque<>------------------------------------------------
void test_deque()
{

	//������ �������� ���������� std::deque<>
	std::deque<string> dq0;									//������ ���������
	std::deque<string> dq1(3);								//��������� �� 3 �������� ������������������ ������ �������������� �� ���������
	std::deque<string> dq2(3, string("simple"));			//��������� �� 3 �������� ���� string ������������������ ��������� "simple"
	std::deque<string> dq3{"Hello", "world", "!!!", "OK"};	//��������� �� ������ ������ ������������� {}

	std::deque<string> dq4(dq2);							//�������� ���������� � ������� ������������ �����������
	std::deque<string> dq5(std::move(dq3));					//�������� ���������� ��� ������ ������������� ������������

	std::deque<string> dq6((++dq5.cbegin()), dq5.cend());	//�������� ���������� �� ������ ��������� �������� ������� ����������


	std::initializer_list<string> text{"BMW","Audi","Opel","Toyota","Volvo","Mercedes","Porshe"};
	std::deque<string> dq7 = text;							//�������� ���������� �� ������ ���������� ������ �������������	{}

	std::deque<string> dq8 = dq2;							//�������� ���������� �� ������ ��������� ����������� ������������
	std::deque<string> dq9 = std::move(dq5);				//�������� ���������� �� ������ ��������� ������������� ������������


	//������ ���������� � ����������
	print_deque_info(dq7);
	print_deque(dq7);


	//��������������� ���������� std::deque<>
	dq7.push_back(string("Pegot"));
	dq7.push_front(string("Citroen"));
	
	dq7.emplace_back("AlfaRomeo");
	dq7.emplace_front("Shevrole");

	dq7.insert(++dq7.cbegin(), string("Mustang"));
	dq7.emplace(++dq7.cbegin(), "Volga");

	print_deque(dq7);
	
	dq7.pop_back();
	dq7.pop_front();
	
	print_deque(dq7);

	dq7.assign(10, string("Bently"));

	print_deque(dq7);

	dq7.assign(text.begin(), text.end());

	print_deque(dq7);

	dq7.erase(--dq7.end());
	
	print_deque(dq7);
	
	dq7.erase(++dq7.begin(), --dq7.end());

	print_deque(dq7);

	dq7.insert(++dq7.begin(), { "Audi","Opel","Toyota","Volvo" } );
	
	print_deque(dq7);

	dq7.clear();

	print_deque(dq7);

	dq7.resize(5, string("some string"));
	print_deque(dq7);

	dq7.resize(7, string("something else"));
	print_deque(dq7);

	dq7.resize(3);
	print_deque(dq7);


	//��������� ��� ������ ���������� std::deque<>
	std::deque<string>::const_iterator ci          = dq7.begin();
	std::deque<string>::iterator it                = dq7.begin();
	std::deque<string>::const_reverse_iterator cri = dq7.crbegin();
	std::deque<string>::reverse_iterator ri        = dq7.rbegin();

	cout << endl;
	for (; ci != dq7.end(); ++ci)
		cout << "e - " << (*ci) << endl;

	cout << endl;
	for (; it != dq7.end(); ++it) 
		cout << "e - " << (*it).append("-") << endl;

	cout << endl;
	for (; cri != dq7.crend(); ++cri)
		cout << "e <- " << (*cri) << endl;

	cout << endl;
	for (; ri != dq7.rend(); ++ri)
	{
		(*ri).at((*ri).size() - 1) = '+';
		cout << "e <- " << (*ri) << endl;
	}

}


bool rmbig(int a)
{
	return (a > 1000 ? true:false);
}

//-------------------------------------������������ ���������� std::list<>-------------------------------------------------
void test_list()
{
	//������ �������� ���������� std::list<>
	std::list<int> lst0;							//������ ������
	std::list<int> lst1(5);							//������ �� 5-�� ��������� ��������� ������������� �� ���� �� ���������
	std::list<int> lst2(5, 5);						//������ �� 5-�� ��������� 5
	std::list<int> lst3{ 1,9,3,7,0,10,24,12 };		//������ �� ������ ������ �������������
	std::list<int> lst4({ 2,4,5,6,1,0 });			//

	std::list<int> lst5(lst3);						//������ ������ ����� ������ ������������ �����������
	std::list<int> lst6(std::move(lst2));			//������ ������ ����� ������ ������������ �����������
	std::list<int> lst7(lst3.begin(), lst3.end());	//������ ������ �� ������ ��������� ��������� ����������� (begin, end)

	std::initializer_list<int> ini_list{ 9,8,7,6,5,4,3,2,1,0 };
	std::list<int> lst8 = ini_list;					//������ ������ �� ������ ������ �������������
	std::list<int> lst9 = lst8;						//������� ����� ������������ �����������		
	std::list<int> lst10 = std::move(lst9);			//������� ����� ������������ �����������


	print_list(lst0);
	print_list(lst8);
	print_list_info(lst8);

	//�������� ������������
	lst0.assign(ini_list);
	lst1.assign(4, 9990);
	lst2.assign(++lst3.begin(), --lst3.end());

	print_list(lst0);
	print_list(lst1);
	print_list(lst2);

	lst9.assign(ini_list);
	lst1.swap(lst9);

	print_list(lst9);
	print_list(lst1);


	//������ � ���������
	cout << "first element - " << lst1.front() << endl;
	cout << "last  element - " << lst1.back()  << endl;

	//������ �������� ����������
	std::list<int>::const_iterator ci;
	std::list<int>::iterator i;
	std::list<int>::reverse_iterator ri;
	std::list<int>::const_reverse_iterator cri;

	for (ci = lst9.cbegin(); ci != lst9.cend(); ++ci)
		cout << (*ci) << " ";

	cout << endl;
	for (i = lst9.begin(); i != lst9.end(); ++i)
		cout << ((*i) /= 2)<<" ";

	cout << endl;
	for (ri = lst1.rbegin(); ri != lst1.rend(); ++ri)
		cout << ((*ri) *= 2) << " ";

	cout << endl;
	for (cri = lst1.crbegin(); cri != lst1.crend(); ++cri)
		cout << (*cri) << " ";

	cout << endl;

	//����������� ������
	std::initializer_list<int> numbers{ 7,7,7,5,5,5 };
	std::initializer_list<int> big_numbers{ 1000,2000,3000 };
	
	std::list<int> l = numbers;

	l.push_back(10);
	l.push_front(10);
	l.emplace_back(9);
	l.emplace_front(9);

	auto pos = l.begin();
	
	size_t k = l.size();
	size_t half = l.size() / 2;
	while (k > half)
	{
		--k;
		++pos;
	}

	l.insert(pos, 5000);				//������� �������� � �������� ������
	print_list(l);

	l.insert(l.begin(), big_numbers);
	l.insert(l.end(), big_numbers.begin(), big_numbers.end() );
	print_list(l);


	cout << endl << "remove all numbers 9 " << endl;
	l.remove(9);						//������� ��� ����� 9
	print_list(l);						

	cout << endl << "remove all numbers >1000 " << endl;
	l.remove_if(rmbig);
	print_list(l);

	cout << endl << "remove all even numbers " << endl;
	l.remove_if(Rm());
	print_list(l);

	cout << endl << " remove all numbers that can be divided / 5 " << endl;
	l.remove_if([](int a)->bool {
		if ((a % 5) == 0)
			return true;
		else
			return false;
	});
	
	print_list(l);

	cout << endl << "resize to 10 elements" << endl;
	l.resize(10, 3);
	print_list(l);

	cout << endl << "reverse list" << endl;
	l.reverse();
	print_list(l);

	cout << endl << "erase core" << endl;
	l.erase(++l.begin(), --l.end());
	print_list(l);


	cout << endl << "erase first element" << endl;
	l.erase(l.begin());
	print_list(l);

	l.clear();

}

void test_list_special()
{
	//����������� �������������� �������� ��� ��������



















}



















