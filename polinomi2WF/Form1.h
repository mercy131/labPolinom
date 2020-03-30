#pragma once
#include "Polinom.h"
namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	void MarshalString(String^ s, std::string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ textBox6;

	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(355, 28);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(117, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::TextBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(509, 28);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::TextBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(641, 26);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Act";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::Button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(309, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"max st:";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::Label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(487, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"n:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(134, 102);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(369, 20);
			this->textBox3->TabIndex = 5;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::TextBox3_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(78, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Polinom1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(78, 157);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Polinom2";
			this->label4->Click += gcnew System::EventHandler(this, &Form1::Label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(88, 248);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Result:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(134, 150);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(369, 20);
			this->textBox4->TabIndex = 9;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(134, 245);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(369, 20);
			this->textBox5->TabIndex = 10;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &Form1::TextBox5_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(154, 202);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"*";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::Button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(235, 202);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 12;
			this->button3->Text = L"-";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::Button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(550, 243);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(28, 23);
			this->button4->TabIndex = 13;
			this->button4->Text = L"*";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::Button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(325, 202);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 14;
			this->button5->Text = L"+";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::Button5_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(584, 245);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(61, 20);
			this->textBox6->TabIndex = 15;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"ADD", L"DEL" });
			this->listBox1->Location = System::Drawing::Point(535, 92);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(33, 30);
			this->listBox1->TabIndex = 17;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::ListBox1_SelectedIndexChanged);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"ADD", L"DEL" });
			this->listBox2->Location = System::Drawing::Point(535, 140);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(33, 30);
			this->listBox2->TabIndex = 18;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::ListBox2_SelectedIndexChanged);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(600, 150);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 19;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &Form1::TextBox7_TextChanged);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(600, 102);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 20;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &Form1::TextBox8_TextChanged);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(706, 100);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 21;
			this->button6->Text = L"Act";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::Button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(706, 150);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 22;
			this->button7->Text = L"Act";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::Button7_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(802, 374);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int n;
		int b = 0;
		int c = 0;
		int max_st;
		int r = 0;
		Polinom* p1;
		Polinom* p2;
		Polinom* res;
		
		
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		std::string sl1;
		std::string sl2;
		MarshalString(textBox3->Text, sl1);
		MarshalString(textBox4->Text, sl2);
		p1 = new Polinom(sl1, n, max_st);
		p2 = new Polinom(sl2, n, max_st);
	}
	private: System::Void TextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {



	}
private: System::Void Label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	std::string smax_st;
	std::string sn;
	MarshalString(textBox1->Text, smax_st);
	MarshalString(textBox2->Text, sn);
	textBox1->ReadOnly=true;
	textBox2->ReadOnly=true;
	n = stoi(sn);
	max_st = stoi(smax_st);

}
private: System::Void TextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	

}
private: System::Void TextBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ListBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	

}
private: System::Void TextBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TextBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Button6_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (b == 0)
	{
		p1 = new Polinom("", n, max_st);
		
	}
	if (listBox1->SelectedIndex == 0)
	{
		std::string sbf1;
		MarshalString(textBox8->Text, sbf1);
		Monom buff1(sbf1, max_st, n);
		p1->add(buff1);
		System::String^ strCLR2 = gcnew System::String(p1->to_string().c_str());
		textBox3->Text = strCLR2;
		b = 1;

	}
	if (listBox1->SelectedIndex == 1)
	{
		std::string sbf1;
		MarshalString(textBox8->Text, sbf1);
		Monom buff1(sbf1, max_st, n);
		p1->erase(buff1);
		System::String^ strCLR2 = gcnew System::String(p1->to_string().c_str());
		textBox3->Text = strCLR2;
		b = 1;
	}

}
private: System::Void Button7_Click(System::Object^ sender, System::EventArgs^ e) {
	if (c == 0)
	{
		
		p2 = new Polinom("", n, max_st);
	}
	if (listBox2->SelectedIndex == 0)
	{
		std::string sbf2;
		MarshalString(textBox7->Text, sbf2);
		Monom buff1(sbf2, max_st, n);
		p2->add(buff1);
		System::String^ strCLR2 = gcnew System::String(p2->to_string().c_str());
		textBox4->Text = strCLR2;
		c = 1;

	}
	if (listBox2->SelectedIndex == 1)
	{
		std::string sbf1;
		MarshalString(textBox7->Text, sbf1);
		Monom buff1(sbf1, max_st, n);
		p2->erase(buff1);
		System::String^ strCLR2 = gcnew System::String(p2->to_string().c_str());
		textBox4->Text = strCLR2;
		c = 1;
	}
}
private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
	res = new Polinom("", max_st, n);
	r = 1;
	*res = *p1 * (*p2);
	System::String^ strCLR2 = gcnew System::String(res->to_string().c_str());
	textBox5->Text = strCLR2;
}
private: System::Void TextBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
	res = new Polinom("", max_st, n);
	r = 1;
	*res = (*p1)-(*p2);
	System::String^ strCLR2 = gcnew System::String(res->to_string().c_str());
	textBox5->Text = strCLR2;

}
private: System::Void Button5_Click(System::Object^ sender, System::EventArgs^ e) {
	res = new Polinom("", max_st, n);
	r = 1;
	*res = (*p1) + (*p2);
	System::String^ strCLR2 = gcnew System::String(res->to_string().c_str());
	textBox5->Text = strCLR2;

}
private: System::Void Button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (r == 0)
	{
		res = new Polinom("", max_st, n);
	}
	

	std::string tt;
	MarshalString(textBox6->Text, tt);
	*res = (*res) * stod(tt);
	System::String^ strCLR2 = gcnew System::String(res->to_string().c_str());
	textBox5->Text = strCLR2;
}
};
}
