#pragma once
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

wifstream fin("input.txt");
wofstream fout("output.txt");
map<wstring, int> pred_so;
map<wstring, int> ::iterator it;
wstring znaki = L".,?:!«»";
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
	{L"Ч" , L"ч"}
};

set<wstring> ne_pred =
{
	L"я", L"мы", L"вы",L"ему", L"мог", L"мой" ,L"нам",L"нас",L"той",L"ума",L"он",L"это",L"три",L"был",L"все",L"дня",L"ее",L"его",L"их",L"она",L"ей",L"не"
};

set<wstring> b_pred =
{
	L"чтобы",L"если",L"хотя"
};

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
			if (st[0] == znaki[i])
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

void obrab(vector<wstring> vvod) 
{
	wstring st;
	for (wstring cur : vvod) {
		st += cur;
		st += ' ';
	}
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
		if ((pos_prob <= 3 && slovo != L"-" && slovo != L"—" && ne_pred.find(slovo) == ne_pred.end()) || b_pred.find(slovo) != b_pred.end())
		{
			it = pred_so.find(slovo);
			if (it == pred_so.end())
			{
				pair<wstring, int> par;
				par = make_pair(slovo, 1);
				pred_so.insert(par);
			}
			else
			{
				it->second++;
			}
		}
		st.erase(0, pos_prob);
	}
}

void vout() {
	int maxx1 = 0, maxx2 = 0, maxx3 = 0, i = 0;
	wstring st1 = L"", st2 = L"", st3 = L"";
	for (it = pred_so.begin(); it != pred_so.end(); it++)
	{
		wstring st = it->first;
		fout << st << ": ";
		if (st.length() == 1) fout << "    ";
		if (st.length() == 2) fout << "   ";
		if (st.length() == 3) fout << "  ";
		if (st.length() == 4) fout << " ";
		int a = it->second;
		fout << a << ", ";
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
	fout << endl << "TOP 3 most popular: " << st1 << ", " << st2 << ", " << st3;
}

void solve_3(vector<wstring> vvod) {
	obrab(vvod);
	vout();
}