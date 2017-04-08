#pragma once
#include "stdio.h"


#include <string>
#include <iostream>
using namespace std;
namespace MyApp1 {
	struct List
	{
		int val;
		int pow;
		List *n;
	};

	class TList
	{
		List *f;

	public:
		TList()
		{
			f = NULL;

		};
	//	~TList()
	//	{
	//		delete f;
	//	};

	
		void push(int m, int n)
		{
			int flag = -1;

			if (f == NULL) // если не было элементов 
			{
				List *temp;
				temp = new List;
				temp->val = m;
				temp->pow = n;
				temp->n = f;
				f = temp;

			}
			else
			{
				List *temp = f;

				List *newtemp;
				newtemp = new List;
				newtemp->val = m;
				newtemp->pow = n;


				if (temp->pow > newtemp->pow)
				{
					f = newtemp;
					newtemp->n = temp;

					flag = 1;
				}
				else
				{

					while (temp->n != NULL)
					{
						if (temp->pow > newtemp->pow)
						{

							List *temp2 = f;

							while (temp2->n != temp)
							{
								temp2 = temp2->n;
							}

							newtemp->n = temp2->n;
							temp2->n = newtemp;
							temp = temp->n;
							flag = 1; // вставили элемент
						}
						else if (temp->pow == newtemp->pow)
						{
							temp->val += newtemp->val;
							flag = 1;
							temp = temp->n;
							break;

						}
						else
						{
							temp = temp->n;
						}
					}

					if ((temp->n == NULL) && (temp->pow > newtemp->pow) && (flag != 1)) // если предпоследний
					{
						flag = 1;
						List *temp2 = f;

						while (temp2->n != temp)
						{
							temp2 = temp2->n;
						}

						newtemp->n = temp2->n;
						temp2->n = newtemp;
					}

					if (flag < 0) // вставили в конец списка
					{
						temp->n = newtemp;
						newtemp->n = NULL;
					}
				}
			}
		}

		void take()
		{
			if (f == NULL) { throw "no elem"; }
			else
			{
				int val = f->val;
				List * temp = f;
				f = f->n;
				delete temp;
				//return val;
			}
		};


		string show()
		{
			List *temp;
			temp = f;
			cout << " Value :  ";
			string s = "[";
			while (temp != NULL)
			{
				s += std::to_string(temp->val);
				s += " ";
				s += std::to_string(temp->pow);
				s += "     ";
				temp = temp->n;
			}
			s += "]";

			cout << s;
		};

		TList add(TList& v1, TList& v2)
		{
			List *temp2 = v2.f;
			List *temp1 = v1.f;
			TList abc;

			while ((temp1 != NULL) && (temp2 != NULL))
			{
				if (temp1->pow < temp2->pow)
				{
					abc.push(temp1->val, temp1->pow);
					temp1 = temp1->n;
				}
				else
					if (temp1->pow > temp2->pow)
					{
						abc.push(temp2->val, temp2->pow);
						temp2 = temp2->n;
					}
					else
					{
						int s = (temp1->val) + (temp2->val);
						abc.push(s, temp1->pow);
						temp1 = temp1->n;
						temp2 = temp2->n;
					}
			}

			if (temp1 != NULL)
				while (temp1 != NULL)
				{
					abc.push(temp1->val, temp1->pow);
					temp1 = temp1->n;
				}
			if (temp2 != NULL)
				while (temp2 != NULL)
				{
					abc.push(temp2->val, temp2->pow);
					temp2 = temp2->n;
				}
			return abc;

		}


		TList subtract(TList& v1, TList& v2)
		{
			List *temp2 = v2.f;
			List *temp1 = v1.f;
			TList abc;

			while ((temp1 != NULL) && (temp2 != NULL))
			{
				if (temp1->pow < temp2->pow)
				{
					abc.push(temp1->val, temp1->pow);
					temp1 = temp1->n;
				}
				else
					if (temp1->pow > temp2->pow)
					{
						abc.push((temp2->val)*(-1), temp2->pow);
						temp2 = temp2->n;
					}
					else
					{
						int s = (temp1->val) + (temp2->val)*(-1);
						abc.push(s, temp1->pow);
						temp1 = temp1->n;
						temp2 = temp2->n;
					}
			}

			if (temp1 != NULL)
				while (temp1 != NULL)
				{
					abc.push(temp1->val, temp1->pow);
					temp1 = temp1->n;
				}
			if (temp2 != NULL)
				while (temp2 != NULL)
				{
					abc.push((temp2->val)*(-1), temp2->pow);
					temp2 = temp2->n;
				}
			return abc;

		}


		TList multiply(TList& v1, TList& v2)
		{
			List *temp2 = v2.f;
			List *temp1 = v1.f;
			TList abc;

			while (temp1 != NULL)
			{
				while (temp2 != NULL)
				{
					abc.push((temp1->val)*(temp2->val), (temp1->pow) + (temp2->pow));
					temp2 = temp2->n;
				}
				temp1 = temp1->n;
			}

			return abc;

		}


		double countvalue( int x, int y, int z)
		{
			double res = 0;
			int stepx, stepy, stepz;
			List *temp = f;

			//stringstream ss;
			while (temp != NULL)
			{
				int poww = temp->pow;
				stepx = poww / (19 * 19);
				stepy = (poww % (19 * 19)) / 19;
				stepz = (poww % (19 * 19)) % 19;
				res = res + temp->val*(pow(x, stepx))*(pow(y, stepy))*(pow(z, stepz));

				temp = temp->n;

			}

			return res;
		}
		
		

		string ToString()
		{
			string s;
			List *temp;
			temp = f;
			//stringstream ss;
			while (temp != NULL)
			{
				int poww = temp->pow;
				s += "+";
				s += std::to_string(temp->val);
				s += "x^";
				int powxx = temp->pow / (19 * 19);
				s += std::to_string(powxx);
				s += "y^";
				int powyy = (temp->pow % (19 * 19)) / 19;
				s += std::to_string(powyy);
				s += "z^";
				int powzz = (temp->pow % (19 * 19)) % 19;
				s += std::to_string(powzz);

				temp = temp->n;
		
			}

			return s;

		};


		bool TList::IsEmpty()
		{
			if (f == NULL) {

				cout << 1;
				return true;
			}
			else
			{
				cout << 0;
				return false;
			}


		};
	};
};