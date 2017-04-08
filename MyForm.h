#pragma once
#include "StackOnLists.h"
#include <string>
#include <iostream>
namespace MyApp1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		TList *polinom;
	private: System::Windows::Forms::Label^  label26;
	public:
		TList *polinom1;

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			polinom = new TList;
		}


	private: System::Windows::Forms::ComboBox^  comboBox2;
	public:
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::ComboBox^  comboBox6;

		int n;

	


	private: System::Windows::Forms::Label^  label3;
	
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	public:
			 int nom;
	private: System::Windows::Forms::Label^  label6;
	public:
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;



public:
	int SetPow(int x, int y, int z)
		{
			int pow = x * 19 * 19 + y * 19 + z * 1;
			return pow;
		}


	void MarshalString(String ^s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		void  convert(TextBox ^t, TList &ab)
		{


			String  ^s;
			s = t->Text;

			string str;
			MarshalString(s, str);
			int size = str.size();
			str += '+';
			string newstr = str;
			
			string podstr;
			//TList abc;
			int k, c;
			k = str.size();
			int flag = 0;
			int dlina = 0;
			c = 0;
			int i = 0;
			int px, py, pz;
			string koef;
			koef = "";
			string step;
			step = "";
			int j = 0;





			while (i != (k - 1))
			{
				if ((str[i] == '-') || (str[i] == '+'))
				{
					if (str[i] == '-')
					{
						flag = 1;
						i++;
					}
					else
					{
						flag = 2;
						i++;
					}

					//newstr.erase(0, 1);
				}

				px = 0; py = 0; pz = 0;
				podstr = "";
				while ((newstr[i] != '+') && (newstr[i] != '-'))    // выдел€ю подстроку ( моном ) в строке ( полиноме )
				{

					podstr += newstr[i];
					i++;
				}

				dlina = podstr.size();


				while ((podstr[j] != 'x') && (podstr[j] != 'y') && (podstr[j] != 'z')) // узнаю коэффициент 
				{
					koef += podstr[j];
					j++;
				}
				//j += dlina;
				int koef1 = atoi(koef.c_str());  // привожу к численному значению
				if (flag == 1) koef1 = -koef1; // будущий VAL в звене 

				for (int ii = 0; ii < dlina; ii++)
				{
					if (podstr[ii] == 'x')
					{
						step += podstr[ii + 2];
						if ((podstr[ii + 3] != 'y') && (podstr[ii + 3] != 'z'))
						{
							step += podstr[ii + 3];
						}
						px = atoi(step.c_str());
						step = "";
					}


					if (podstr[ii] == 'y')
					{
						step += podstr[ii + 2];
						if (podstr[ii + 3] != 'z')
						{
							step += podstr[ii + 3];
						}

						py = atoi(step.c_str());
						step = "";
					}



					if (podstr[ii] == 'z')
					{
						step += podstr[ii + 2];
						if ((podstr[ii + 3] != '+') && (podstr[ii + 3] != '-'))
						{
							step += podstr[ii + 3];
						}

						pz = atoi(step.c_str());
						step = "";
					}
				}


				int ppow = 0;
				ppow = SetPow(px, py, pz);
				ab.push(koef1, ppow);
				//abc.show();
				//i++;
				flag = 0;
				j = 0;
				koef = "";
			}
		//	return abc;
		}

		void convert(Label ^t, TList &ab)
		{


			String  ^s;
			s = t->Text;

			string str;
			MarshalString(s, str);
			int size = str.size();
			str += '+';
			string newstr = str;

			string podstr;
			//TList abc;
			int k, c;
			k = str.size();
			int flag = 0;
			int dlina = 0;
			c = 0;
			int i = 0;
			int px, py, pz;
			string koef;
			koef = "";
			string step;
			step = "";
			int j = 0;





			while (i != (k - 1))
			{
				if ((str[i] == '-') || (str[i] == '+'))
				{
					if (str[i] == '-')
					{
						flag = 1;
						i++;
					}
					else
					{
						flag = 2;
						i++;
					}

					//newstr.erase(0, 1);
				}

				px = 0; py = 0; pz = 0;
				podstr = "";
				while ((newstr[i] != '+') && (newstr[i] != '-'))    // выдел€ю подстроку ( моном ) в строке ( полиноме )
				{

					podstr += newstr[i];
					i++;
				}

				dlina = podstr.size();


				while ((podstr[j] != 'x') && (podstr[j] != 'y') && (podstr[j] != 'z')) // узнаю коэффициент 
				{
					koef += podstr[j];
					j++;
				}
				//j += dlina;
				int koef1 = atoi(koef.c_str());  // привожу к численному значению
				if (flag == 1) koef1 = -koef1; // будущий VAL в звене 

				for (int ii = 0; ii < dlina; ii++)
				{
					if (podstr[ii] == 'x')
					{
						step += podstr[ii + 2];
						if ((podstr[ii + 3] != 'y') && (podstr[ii + 3] != 'z'))
						{
							step += podstr[ii + 3];
						}
						px = atoi(step.c_str());
						step = "";
					}


					if (podstr[ii] == 'y')
					{
						step += podstr[ii + 2];
						if (podstr[ii + 3] != 'z')
						{
							step += podstr[ii + 3];
						}

						py = atoi(step.c_str());
						step = "";
					}



					if (podstr[ii] == 'z')
					{
						step += podstr[ii + 2];
						if ((podstr[ii + 3] != '+') && (podstr[ii + 3] != '-'))
						{
							step += podstr[ii + 3];
						}

						pz = atoi(step.c_str());
						step = "";
					}
				}


				int ppow = 0;
				ppow = SetPow(px, py, pz);
				ab.push(koef1, ppow);
				//abc.show();
				//i++;
				flag = 0;
				j = 0;
				koef = "";
			}
			//	return abc;
		}


		

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label2;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(471, 31);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 25);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(97, 34);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(354, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"є";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(103, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 84);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"1";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10"
			});
			this->comboBox1->Location = System::Drawing::Point(29, 33);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(32, 21);
			this->comboBox1->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(27, 116);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"2";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(103, 116);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 13);
			this->label5->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(27, 149);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"3";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(103, 149);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 13);
			this->label7->TabIndex = 11;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(27, 180);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(13, 13);
			this->label8->TabIndex = 12;
			this->label8->Text = L"4";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(103, 180);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 13);
			this->label9->TabIndex = 13;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(27, 209);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(13, 13);
			this->label10->TabIndex = 14;
			this->label10->Text = L"5";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(103, 209);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 13);
			this->label11->TabIndex = 15;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(27, 244);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(13, 13);
			this->label12->TabIndex = 16;
			this->label12->Text = L"6";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(103, 244);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 13);
			this->label13->TabIndex = 17;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(27, 281);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(13, 13);
			this->label14->TabIndex = 18;
			this->label14->Text = L"7";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(103, 281);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(0, 13);
			this->label15->TabIndex = 19;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(27, 317);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(13, 13);
			this->label16->TabIndex = 20;
			this->label16->Text = L"8";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(27, 349);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(13, 13);
			this->label17->TabIndex = 21;
			this->label17->Text = L"9";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(27, 385);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(19, 13);
			this->label18->TabIndex = 22;
			this->label18->Text = L"10";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(103, 317);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(0, 13);
			this->label19->TabIndex = 23;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(103, 349);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(0, 13);
			this->label20->TabIndex = 24;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(103, 385);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(0, 13);
			this->label21->TabIndex = 25;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10"
			});
			this->comboBox2->Location = System::Drawing::Point(86, 445);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(44, 21);
			this->comboBox2->TabIndex = 26;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"+", L"-", L"*" });
			this->comboBox3->Location = System::Drawing::Point(150, 445);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(43, 21);
			this->comboBox3->TabIndex = 27;
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10"
			});
			this->comboBox4->Location = System::Drawing::Point(212, 445);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(44, 21);
			this->comboBox4->TabIndex = 28;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(414, 448);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 29;
			this->button2->Text = L"count";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10"
			});
			this->comboBox5->Location = System::Drawing::Point(341, 447);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(39, 21);
			this->comboBox5->TabIndex = 30;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(106, 506);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(54, 20);
			this->textBox2->TabIndex = 31;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(212, 506);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(56, 20);
			this->textBox3->TabIndex = 32;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(314, 506);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(66, 20);
			this->textBox4->TabIndex = 33;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(523, 510);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(0, 13);
			this->label22->TabIndex = 34;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(414, 505);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 35;
			this->button3->Text = L"count";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(83, 509);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(17, 13);
			this->label23->TabIndex = 36;
			this->label23->Text = L"X ";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(192, 511);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(14, 13);
			this->label24->TabIndex = 37;
			this->label24->Text = L"Y";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(294, 510);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(14, 13);
			this->label25->TabIndex = 38;
			this->label25->Text = L"Z";
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10"
			});
			this->comboBox6->Location = System::Drawing::Point(15, 506);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(46, 21);
			this->comboBox6->TabIndex = 39;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(283, 448);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(25, 13);
			this->label26->TabIndex = 40;
			this->label26->Text = L"Into";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(644, 569);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
	//	String ^ textboxtext = textBox1->Text;
		int val1 = Convert::ToInt32(comboBox1->Text); // номер строки
		int nom = val1;
		//string polinomstring;

		//MarshalString(stroka, polinomstring);
		//	int Sizeps = polinomstring.size();


			TList pol;
			convert(textBox1, pol);

			String ^ stroka = gcnew String(pol.ToString().c_str());
		//	String ^ stroka = "123";

			switch (nom)
			{
			case 1:{
				label2->Text = stroka;
				break; }
			case 2:{
				label5->Text = stroka;
				break; }
			case 3:{
				label7->Text = stroka;
				break; }
			case 4:{
				label9->Text = stroka;
				break; }
			case 5:{
				label11->Text = stroka;
				break; }
			case 6:{
				label13->Text = stroka;
				break; }
			case 7:{
				label15->Text = stroka;
				break; }
			case 8:{
				label19->Text = stroka;
				break; }
			case 9:{
				label20->Text = stroka;
				break; }
			case 10:{
				label21->Text = stroka;
				break; }
			}

			textBox1->Text= "";



	}




private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	TList pol1, pol2, res, res1;
	int one = Convert::ToInt32(comboBox2->Text); // первый полином 
	int nom2 = one;
	int two = Convert::ToInt32(comboBox4->Text); // первый полином 
	int nom4 = two;
	int into = Convert::ToInt32(comboBox5->Text); // первый полином 
	int into1 = into;
	int op = Convert::ToInt32(comboBox3->SelectedIndex); // первый полином 
	int operation = op;

	switch (nom2)
	{
	
	case 1: convert(label2, pol1); break;
	case 2: convert(label5, pol1); break;
	case 3: convert(label7, pol1); break;
	case 4: convert(label9, pol1); break;
	case 5: convert(label11, pol1); break;
	case 6: convert(label13, pol1); break;
	case 7: convert(label15, pol1); break;
	case 8: convert(label19, pol1); break;
	case 9: convert(label20, pol1); break;
	case 10: convert(label21, pol1); break;
	}
	
	switch (nom4)
	{

	case 1: convert(label2, pol2); break;
	case 2: convert(label5, pol2); break;
	case 3: convert(label7, pol2); break;
	case 4: convert(label9, pol2); break;
	case 5: convert(label11, pol2); break;
	case 6: convert(label13, pol2); break;
	case 7: convert(label15, pol2); break;
	case 8: convert(label19, pol2); break;
	case 9: convert(label20, pol2); break;
	case 10: convert(label21, pol2); break;
	}



	switch (operation)
	{

	case 0: { res1 = res.add(pol1, pol2);
		; break; }
	case 1: { res1 = res.subtract(pol1, pol2);; break; }
	case 2: { res1 = res.multiply(pol1, pol2);; break; }
	
	}


	String^ sresult = gcnew String(res1.ToString().c_str());

	switch (into1)
	{
		

		{
	case 1:{
		label2->Text = sresult;
		break; }
	case 2:{
		label5->Text = sresult;
		break; }
	case 3:{
		label7->Text = sresult;
		break; }
	case 4:{
		label9->Text = sresult;
		break; }
	case 5:{
		label11->Text = sresult;
		break; }
	case 6:{
		label13->Text = sresult;
		break; }
	case 7:{
		label15->Text = sresult;
		break; }
	case 8:{
		label19->Text = sresult;
		break; }
	case 9:{
		label20->Text = sresult;
		break; }
	case 10:{
		label21->Text = sresult;
		break; }
		}

	}


}





private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	int nomm = Convert::ToInt32(comboBox6->Text); // первый полином 
	int nommm = nomm;
	TList knowvalue; 

	switch (nommm)
	{

	case 1: convert(label2, knowvalue); break;
	case 2: convert(label5, knowvalue); break;
	case 3: convert(label7, knowvalue); break;
	case 4: convert(label9, knowvalue); break;
	case 5: convert(label11, knowvalue); break;
	case 6: convert(label13, knowvalue); break;
	case 7: convert(label15, knowvalue); break;
	case 8: convert(label19, knowvalue); break;
	case 9: convert(label20, knowvalue); break;
	case 10: convert(label21, knowvalue); break;
	}

	String ^ X = textBox2->Text;
	String ^ Y = textBox3->Text;
	String ^ Z = textBox4->Text;

	string x, y, z;
	MarshalString(X, x);
	MarshalString(Y, y);
	MarshalString(Z, z);


	int koefX = atoi(x.c_str());
	int koefY = atoi(y.c_str());
	int koefZ = atoi(z.c_str());

	
	double res123 = knowvalue.countvalue( koefX, koefY, koefZ);
	

	
	
	int res12345 = (int)res123;
	string str = to_string(res12345);
	String ^ res1234 = gcnew String(str.c_str());
	label22->Text = res1234 ;


}
};
}
