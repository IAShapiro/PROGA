#pragma once

#include "Raylway.h"

namespace Source {
	raylway A;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	std::string ToStr(int k) {
		if (k >= 1 && k <= 9)
		{
			return ("0" + std::to_string(k));
		}
		return std::to_string(k);
	}


	int SearchIndexInDGV2(System::String^ numb, System::Windows::Forms::DataGridView^ a)
	{
		for (auto i = 0; i < a->RowCount; i++)
		{
			if (a->Rows[i]->Cells[5]->Value->ToString() == numb)
			{
				return i;
			}
		}
		return -2;
	}


	/// <summary>
	/// Zusammenfassung fьr Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufьgen.
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
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:







	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::ComboBox^  comboBox6;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewButtonColumn^  Column14;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column11;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column13;















	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode fьr die Designerunterstьtzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geдndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column14 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column14, this->Column6, this->Column7
			});
			this->dataGridView1->Location = System::Drawing::Point(644, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(758, 437);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView1_CellContentClick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->button1->Location = System::Drawing::Point(42, 97);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(243, 51);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Найти в диапазоне";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(20) {
				L"2019", L"2020", L"2021", L"2022", L"2023", L"2024",
					L"2025", L"2026", L"2027", L"2028", L"2029", L"2030", L"2031", L"2032", L"2033", L"2034", L"2035", L"2036", L"2037", L"2038"
			});
			this->comboBox1->Location = System::Drawing::Point(23, 20);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(79, 21);
			this->comboBox1->TabIndex = 2;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(20) {
				L"2019", L"2020", L"2021", L"2022", L"2023", L"2024",
					L"2025", L"2026", L"2027", L"2028", L"2029", L"2030", L"2031", L"2032", L"2033", L"2034", L"2035", L"2036", L"2037", L"2038"
			});
			this->comboBox2->Location = System::Drawing::Point(23, 56);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(79, 21);
			this->comboBox2->TabIndex = 3;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"01", L"02", L"03", L"04", L"05", L"06", L"07",
					L"08", L"09", L"10", L"11", L"12"
			});
			this->comboBox3->Location = System::Drawing::Point(125, 20);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(79, 21);
			this->comboBox3->TabIndex = 4;
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"01", L"02", L"03", L"04", L"05", L"06", L"07",
					L"08", L"09", L"10", L"11", L"12"
			});
			this->comboBox4->Location = System::Drawing::Point(125, 56);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(79, 21);
			this->comboBox4->TabIndex = 7;
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(31) {
				L"01", L"02", L"03", L"04", L"05", L"06", L"07",
					L"08", L"09", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25",
					L"26", L"27", L"28", L"29", L"30", L"31"
			});
			this->comboBox5->Location = System::Drawing::Point(228, 20);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(79, 21);
			this->comboBox5->TabIndex = 6;
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(31) {
				L"01", L"02", L"03", L"04", L"05", L"06", L"07",
					L"08", L"09", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25",
					L"26", L"27", L"28", L"29", L"30", L"31"
			});
			this->comboBox6->Location = System::Drawing::Point(228, 56);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(79, 21);
			this->comboBox6->TabIndex = 5;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(33, 181);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(274, 20);
			this->textBox1->TabIndex = 8;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->button2->Location = System::Drawing::Point(42, 225);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(243, 51);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Найти по станции отпр.";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column8,
					this->Column9, this->Column10, this->Column11, this->Column12, this->Column13
			});
			this->dataGridView2->Location = System::Drawing::Point(23, 296);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(544, 239);
			this->dataGridView2->TabIndex = 10;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Станция отпр.";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Время отпр.";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Станция приб.";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Время приб.";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Билеты";
			this->Column5->Name = L"Column5";
			// 
			// Column14
			// 
			this->Column14->HeaderText = L"Забронировать";
			this->Column14->Name = L"Column14";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Номер структуры";
			this->Column6->Name = L"Column6";
			this->Column6->Visible = false;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Кол-во брони";
			this->Column7->Name = L"Column7";
			this->Column7->Visible = false;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Станция отпр.";
			this->Column8->Name = L"Column8";
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"Время отпр.";
			this->Column9->Name = L"Column9";
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"Станция приб.";
			this->Column10->Name = L"Column10";
			// 
			// Column11
			// 
			this->Column11->HeaderText = L"Время приб.";
			this->Column11->Name = L"Column11";
			// 
			// Column12
			// 
			this->Column12->HeaderText = L"Бронь";
			this->Column12->Name = L"Column12";
			// 
			// Column13
			// 
			this->Column13->HeaderText = L"Номер структуры";
			this->Column13->Name = L"Column13";
			this->Column13->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1431, 565);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		std::string str1 = std::to_string(comboBox1->SelectedIndex + 2019) + "-" + ToStr(comboBox3->SelectedIndex + 1) + "-" + ToStr(comboBox5->SelectedIndex + 1) +
			" 00:00";
		std::string str2 = std::to_string(comboBox2->SelectedIndex + 2019) + "-" + ToStr(comboBox4->SelectedIndex + 1) + "-" + ToStr(comboBox6->SelectedIndex + 1) +
			" 23:59";

		dataGridView1->RowCount = 0;

		for (auto i = 0; i < A.get_size(); i++)
		{
			if (str1 <= A[i].data_time1 && A[i].data_time1 <= str2)
			{
				std::string a[] = { A[i].station1, A[i].data_time1,  A[i].station2, A[i].data_time2, std::to_string(A[i].residue), std::to_string(A[i].n_of_booking) };

				dataGridView1->Rows->Add(gcnew array<System::String ^>(8) {
					gcnew System::String(a[0].c_str()), gcnew System::String(a[1].c_str()),
						gcnew System::String(a[2].c_str()), gcnew System::String(a[3].c_str()), gcnew System::String(a[4].c_str()), "", (i).ToString(), gcnew System::String(a[5].c_str())
				});
			}
		}
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	dataGridView1->RowCount = 0;
	if (textBox1->Text != "")
	{
		System::String^ Line = textBox1->Lines[0];
		for (auto i = 0; i < A.get_size(); i++)
		{
			std::string a[] = { A[i].station1, A[i].data_time1,  A[i].station2, A[i].data_time2, std::to_string(A[i].residue), std::to_string(A[i].n_of_booking) };

			System::String^ b = gcnew System::String(a[0].c_str());
			if (b == Line)
			{
				dataGridView1->Rows->Add(gcnew array<System::String ^>(8) {
					gcnew System::String(a[0].c_str()), gcnew System::String(a[1].c_str()),
						gcnew System::String(a[2].c_str()), gcnew System::String(a[3].c_str()), gcnew System::String(a[4].c_str()), "", (i).ToString(), gcnew System::String(a[5].c_str())
				});
			}
		}
	}
}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	if (e->ColumnIndex == 5 && e->RowIndex != -1)
	{
		if (dataGridView1->Rows[e->RowIndex]->Cells[4]->Value->ToString() != "0")
		{
			A[Int32::Parse(dataGridView1->Rows[e->RowIndex]->Cells[6]->Value->ToString())].residue--;
			A[Int32::Parse(dataGridView1->Rows[e->RowIndex]->Cells[6]->Value->ToString())].n_of_booking++;
			int n = 0;
			int i = Int32::Parse(dataGridView1->Rows[e->RowIndex]->Cells[4]->Value->ToString());
			dataGridView1->Rows[e->RowIndex]->Cells[4]->Value = (i - 1).ToString();
			dataGridView1->Rows[e->RowIndex]->Cells[7]->Value = (Int32::Parse(dataGridView1->Rows[e->RowIndex]->Cells[7]->Value->ToString()) + 1).ToString();

			//7
			if ((n = SearchIndexInDGV2(dataGridView1->Rows[e->RowIndex]->Cells[6]->Value->ToString(),dataGridView2)) != -2)
			{
				dataGridView2->Rows[n]->Cells[4]->Value = (Int32::Parse(dataGridView2->Rows[n]->Cells[4]->Value->ToString()) + 1).ToString();
			}
			else
			{//012376

				dataGridView2->Rows->Add((gcnew array<System::String ^>(6) {
					dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString(),
						dataGridView1->Rows[e->RowIndex]->Cells[1]->Value->ToString(),
						dataGridView1->Rows[e->RowIndex]->Cells[2]->Value->ToString(),
						dataGridView1->Rows[e->RowIndex]->Cells[3]->Value->ToString(),
						dataGridView1->Rows[e->RowIndex]->Cells[7]->Value->ToString(),
						dataGridView1->Rows[e->RowIndex]->Cells[6]->Value->ToString()
				}));
			}
		}
	}
}
};
}
