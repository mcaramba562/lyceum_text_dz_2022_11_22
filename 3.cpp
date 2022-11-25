#include <iostream>
#include <Windows.h>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <set>
using namespace std;

wifstream fin("input.txt");
wofstream fout("output.txt");
map<wstring,int> pred_so;
map<wstring, int> ::iterator it;
wstring znaki = L".,?:!«»\"„";
wstring zag_b = L"ЁЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ";
wstring stroch_b = L"ёйцукенгшщзхъфывапролджэячсмитьбю";
map<wstring, wstring> zag_stroch = {
	{L"А" , L"а"},
	{L"Б" , L"б"},
	{L"В" , L"в"},
	{L"Г" , L"г"},
	{L"Д" , L"д"},
	{L"Е" , L"е"},
	{L"Ж" , L"ж"},
	{L"З" , L"з"},
	{L"И" , L"и"},
	{L"К" , L"к"},
	{L"Л" , L"л"},
	{L"М" , L"м"},
	{L"Н" , L"н"},
	{L"О" , L"о"},
	{L"П" , L"п"},
	{L"Р" , L"р"},
	{L"С" , L"с"},
	{L"Т" , L"т"},
	{L"У" , L"у"},
	{L"Э" , L"э"},
	{L"Я" , L"я"},
	{L"Ч" , L"ч"},
	{L"Ш" , L"ш" }
};

set<wstring> ne_pred =
{
	L"пар", L"рук", L"шее",L"зал", L"бал", L"дам" ,L"усы",L"тур",L"ума",L"три",L"был",L"дня",L"не",L"лет",L"шаг",L"шел",L"шею",L"шея",L"ног",L"мог",L"ах",L"том",L"хо-",L"шла",L"бог",L"два",L"две",L"дом",L"миг",L"муж",L"лиц",L"сэр",L"сын",L"яд",L"яде",L"ум",L"ста",L"дна",L"раз",L"ухо",L"дал",L"де",L"джо",L"жив",L"зря",L"час",L"шум",L"пил",L"рот",L"тип",L"имя",L"шли",L"сот",L"сел"
};

set<wstring> b_pred =
{
	L"чтобы",L"если",L"хотя",L"него",L"свою",L"вами",L"свою",L"даже",L"мной", L"потом", L"тоже", L""
};

set<wstring> predlogi =
{
	L"без",L"безо",L"благодаря",L"близ",L"в",L"вблизи",L"ввиду",L"вглубь",L"вдогон",L"вдоль" ,L"взамен",L"включая",L"вкруг",L"вместо",L"вкруг",L"вместо",L"вне",L"внизу",L"внутри",L"внутрь",L"во",L"вовнутрь",L"возле",L"вокруг",L"вопреки",L"вослед",L"впереди",L"вразрез",L"вроде",L"вслед",L"вследствие",L"встречу",L"выключая",L"выше",L"для",L"до",L"за",L"замест",L"из",L"из-за",L"из-под",L"изнутри",L"изо",L"исключая",L"к",L"касаемо",L"касательно",L"ко",L"кончая",L"кроме",L"кругом",L"меж",L"между",L"мимо",L"на",L"наверху",L"навроде",L"навстречу",L"над",L"надо",L"назад",L"несмотря",L"напротив",L"насчёт",L"наподобие",L"насчёт",L"ниже",L"о",L"об",L"обо",L"около",L"от",L"относительно",L"перед",L"передо",L"по",L"поверх",L"под",L"подле",L"подо",L"подобно",L"позади",L"помимо",L"позднее",L"помимо",L"поперёк",L"порядка",L"посередине",L"после",L"посреди",L"посредине",L"пред",L"предо",L"прежде",L"при",L"про",L"промеж",L"против",L"ради",L"с"
};

map <wstring,int> m_predlogi;

set<wstring> souzi =
{
	L"будто",L"вроде",L"да",L"даж",L"едва",L"если",L"же",L"затем",L"зато",L"и",L"или",L"итак",L"кабы",L"как",L"когда",L"ли",L"а",L"аж",L"благо",L"лишь",L"нежели",L"но",L"пока",L"покуда",L"поскольку",L"притом",L"причем",L"пускай",L"пусть",L"раз",L"разве",L"ровно",L"словно",L"так",L"также",L"тоже",L"только",L"точно",L"хоть",L"хотя",L"чем",L"чисто",L"что",L"чтобы",L"чуть",L"якобы"
};

map <wstring, int> m_souzi;

set<wstring> mestoim =
{
	L"я",L"меня",L"мне",L"мной",L"ты",L"тебя",L"тебе",L"тобой",L"он",L"его",L"ему",L"она",L"им",L"нем",L"ее",L"ей",L"ею",L"ней",L"нас",L"нам",L"нами",L"мы",L"вы",L"выс",L"вам",L"вами",L"они",L"их",L"им",L"ими",L"них",L"оно",L"себя",L"себе",L"собой",L"себе",L"кто",L"кого",L"кому",L"кем",L"ком",L"что",L"чего",L"чему",L"чем",L"сколько",L"скольких",L"скольким",L"какой",L"чей",L"какое",L"чье",L"какого",L"чьего",L"какому",L"чьему",L"каким",L"чьим",L"каком",L"чьем",L"какая",L"чья",L"чьей",L"чью",L"какую",L"какой",L"чьей",L"какие",L"чьи",L"каких",L"чьих",L"каким",L"чьим",L"какие",L"чьи",L"каких",L"чьих",L"какими",L"чьими",L"который",L"которое",L"которая",L"которые",L"которого",L"которому",L"который",L"которым",L"котором",L"которой",L"которую",L"которых",L"которым",L"которыми",L"мой",L"ваш",L"мое",L"ваше",L"моя",L"ваша",L"мой",L"ваши",L"такой",L"этот",L"такое",L"это"
};
map <wstring, int> m_mestoim;

void trim(wstring& st)
{

	bool find = 0;
	do
	{
		find = false;
		wstring begins = L" ";  begins[0] = st[0];
		if (st.length() < 1) return;
		wstring ends = L" "; ends[0] = st[st.length() - 1];
		
		if (st[0] == ' ')
		{
			find = true;
			st.erase(0, 1);
		}
		if (st.length() < 1) return;
		for (int i = 0; i < znaki.length(); ++i)
		{
			if(st[0] == znaki[i])
			{
				find = true;
				st.erase(0, 1);
			}
			if (st[st.length() - 1] == znaki[i])
			{
				find = true;
				st.erase(st.length() - 1, 1);
			}
			if (st.length() < 1) return;
		}
	} while (find and st.length());
}

void obrab(wstring st)
{
	st += L" ";
	while (true)
	{
		trim(st);

		int pos_prob = st.find(L" ");
		if (pos_prob == -1 || st.length() <= 1)
		{
			break;
		}
		wstring slovo = st.substr(0, pos_prob);
		trim(slovo);
		if (slovo.length() < 1) continue;
		pos_prob = slovo.length();
		int symbl = slovo[0];
		if (symbl < 1072 && slovo != L"-")
		{
			map<wstring, wstring> ::iterator it1 = zag_stroch.begin();
			wstring ch = L" ";
			ch[0] = slovo[0];
			for (it1 = zag_stroch.begin(); it1 != zag_stroch.end(); it1++)
			{
				if (it1->first == ch) break;
			}
			if (it1 != zag_stroch.end() && it1->first == ch)
			{
				slovo.erase(0, 1);
				ch = it1->second;
				slovo = ch + slovo;
			}
		}
		if (predlogi.find(slovo) != predlogi.end())
		{
			it = m_predlogi.find(slovo);
			if (it == m_predlogi.end())
			{
				pair<wstring, int> par;
				par = make_pair(slovo, 1);
				m_predlogi.insert(par);
			}
			else
			{
				it->second++;
			}
		}
		if (souzi.find(slovo) != souzi.end())
		{
			it = m_souzi.find(slovo);
			if (it == m_souzi.end())
			{
				pair<wstring, int> par;
				par = make_pair(slovo, 1);
				m_souzi.insert(par);
			}
			else
			{
				it->second++;
			}
		}
		if (mestoim.find(slovo) != mestoim.end())
		{
			it = m_mestoim.find(slovo);
			if (it == m_mestoim.end())
			{
				pair<wstring, int> par;
				par = make_pair(slovo, 1);
				m_mestoim.insert(par);
			}
			else
			{
				it->second++;
			}
		}
		st.erase(0, pos_prob);
	}
}

void vout()
{
	int maxx1 = 0, maxx2 = 0, maxx3 = 0,i = 0,kol_pred =0 ;
	wstring st1 = L"", st2 = L"", st3 = L"";
	fout << "Predlogi: " << endl;
	for (it = m_predlogi.begin(); it != m_predlogi.end(); it++)
	{
		wstring st = it->first;
		fout << st << ": ";
		if (st.length() == 1) fout << "    ";
		if (st.length() == 2) fout << "   ";
		if (st.length() == 3) fout << "  ";
		if (st.length() == 4) fout << " ";
		int a = it->second;
		kol_pred += a;
		fout << a << ", ";
		if (it->second < 10) fout << " ";
		if (it->second < 100) fout << " ";
		if (a > maxx1)
		{
			maxx1 = a;
			st3 = st2;
			st2 = st1;
			st1 = it->first;
		}
		else
		{
			if (a > maxx2)
			{
				maxx2 = a;
				st3 = st2;
				st2 = it->first;
			}
			else
			{
				if (a > maxx3)
				{
					maxx3 = a;
					st3 = it->first;
				}
			}
		}
		i++;
		if (i == 5)
		{
			fout << endl;
			i = 0;
		}
	}
	fout << endl << "In total: " << kol_pred;
	fout << endl << "TOP 3 most popular: " << st1 << ", " << st2 << ", " << st3;
	maxx1 = 0, maxx2 = 0, maxx3 = 0, i = 0, kol_pred = 0;
	st1 = L"", st2 = L"", st3 = L"";
	fout << endl <<  "Souzi: " << endl;
	for (it = m_souzi.begin(); it != m_souzi.end(); it++)
	{
		wstring st = it->first;
		fout << st << ": ";
		if (st.length() == 1) fout << "    ";
		if (st.length() == 2) fout << "   ";
		if (st.length() == 3) fout << "  ";
		if (st.length() == 4) fout << " ";
		int a = it->second;
		kol_pred += a;
		fout << a << ", ";
		if (it->second < 10) fout << " ";
		if (it->second < 100) fout << " ";
		if (a > maxx1)
		{
			maxx1 = a;
			st3 = st2;
			st2 = st1;
			st1 = it->first;
		}
		else
		{
			if (a > maxx2)
			{
				maxx2 = a;
				st3 = st2;
				st2 = it->first;
			}
			else
			{
				if (a > maxx3)
				{
					maxx3 = a;
					st3 = it->first;
				}
			}
		}
		i++;
		if (i == 5)
		{
			fout << endl;
			i = 0;
		}
	}
	fout << endl << "In total: " << kol_pred;
	fout << endl << "TOP 3 most popular: " << st1 << ", " << st2 << ", " << st3;
	maxx1 = 0, maxx2 = 0, maxx3 = 0, i = 0, kol_pred = 0;
	st1 = L"", st2 = L"", st3 = L"";
	fout << endl << "Mestoim: " << endl;
	for (it = m_mestoim.begin(); it != m_mestoim.end(); it++)
	{
		wstring st = it->first;
		fout << st << ": ";
		if (st.length() == 1) fout << "    ";
		if (st.length() == 2) fout << "   ";
		if (st.length() == 3) fout << "  ";
		if (st.length() == 4) fout << " ";
		int a = it->second;
		kol_pred += a;
		fout << a << ", ";
		if (it->second < 10) fout << " ";
		if (it->second < 100) fout << " ";
		if (a > maxx1)
		{
			maxx1 = a;
			st3 = st2;
			st2 = st1;
			st1 = it->first;
		}
		else
		{
			if (a > maxx2)
			{
				maxx2 = a;
				st3 = st2;
				st2 = it->first;
			}
			else
			{
				if (a > maxx3)
				{
					maxx3 = a;
					st3 = it->first;
				}
			}
		}
		i++;
		if (i == 5)
		{
			fout << endl;
			i = 0;
		}
	}
	fout << endl << "In total: " << kol_pred;
	fout << endl << "TOP 3 most popular: " << st1 << ", " << st2 << ", " << st3;
}

int main()
{
	while (!fin.eof())
	{
		wstring podst;

		fin.imbue(std::locale("rus_rus.1251"));
		fout.imbue(std::locale("rus_rus.1251"));
		getline(fin, podst);
		obrab(podst);
	}
	vout();
}
