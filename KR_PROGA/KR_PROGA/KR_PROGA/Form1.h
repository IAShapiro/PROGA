#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "Arr.h"
#include "Drugs.h"

myArray<Drugs> Arr;

namespace CppCLR_WinformsProjekt {

	int SearchIndexInDGV2(System::String^ numb, System::Windows::Forms::DataGridView^ a)
	{
		for (auto i = 0; i < a->RowCount; i++)
		{
			if (a->Rows[i]->Cells[3]->Value->ToString() == numb)
			{
				return i;
			}
		}
		return -2;
	}
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewButtonColumn^  Column4;
	private: System::Windows::Forms::DataGridViewButtonColumn^  Column5;




	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column11;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(93, 119);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(317, 41);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Открыть файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(72, 84);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(359, 20);
			this->textBox1->TabIndex = 1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column10
			});
			this->dataGridView1->Location = System::Drawing::Point(510, 13);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(547, 429);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView1_CellContentClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Название";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Количество";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Цена";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Забронировать";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Забронировано";
			this->Column5->Name = L"Column5";
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"номер структуры";
			this->Column10->Name = L"Column10";
			this->Column10->Visible = false;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column6,
					this->Column8, this->Column9, this->Column11
			});
			this->dataGridView2->Location = System::Drawing::Point(15, 178);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(470, 263);
			this->dataGridView2->TabIndex = 3;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Название";
			this->Column6->Name = L"Column6";
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Цена";
			this->Column8->Name = L"Column8";
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"Забронировано";
			this->Column9->Name = L"Column9";
			// 
			// Column11
			// 
			this->Column11->HeaderText = L"Номер структуры";
			this->Column11->Name = L"Column11";
			this->Column11->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1070, 458);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		dataGridView1->RowCount = 0;
		if (textBox1->Text != "")
		{
			System::String^ Line = textBox1->Lines[0];
			msclr::interop::marshal_context context;
			std::ifstream in(context.marshal_as<std::string>(Line));
			if (in.is_open())
			{
				Drugs d;
				
				while (!in.eof()) {
					in >> d;
					Arr.push(d);
					
						std::string a[] = { Arr[Arr.getCount()].name, std::to_string(Arr[Arr.getCount()].count), std::to_string(Arr[Arr.getCount()].price), std::to_string(Arr[Arr.getCount()].n_of_booking) };

						dataGridView1->Rows->Add(gcnew array<System::String ^>(5) {
							gcnew System::String(a[0].c_str()), gcnew System::String(a[1].c_str()),
								gcnew System::String(a[2].c_str()), "", gcnew System::String(a[3].c_str())
						});
					
				}
				in.close();
			}
		}
	}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	if (e->ColumnIndex == 3 && e->RowIndex != -1)
	{
		if (dataGridView1->Rows[e->RowIndex]->Cells[1]->Value->ToString() != "0")
		{
			Arr[Int32::Parse(dataGridView1->Rows[e->RowIndex]->Cells[5]->Value->ToString())].count--;
			Arr[Int32::Parse(dataGridView1->Rows[e->RowIndex]->Cells[5]->Value->ToString())].n_of_booking++;
			int n = 0;
			int i = Int32::Parse(dataGridView1->Rows[e->RowIndex]->Cells[1]->Value->ToString());
			dataGridView1->Rows[e->RowIndex]->Cells[1]->Value = (i - 1).ToString();
			if ((n = SearchIndexInDGV2(dataGridView1->Rows[e->RowIndex]->Cells[5]->Value->ToString(),
				dataGridView2)) != -2)
			{
				dataGridView2->Rows[n]->Cells[1]->Value = (Int32::Parse(dataGridView2->Rows[n]->Cells[1]->Value->ToString()) + 1).ToString();
			}
			else
			{
				dataGridView2->Rows->Add((gcnew array<System::String ^>(3) {
					dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString(),
						(Arr[Int32::Parse(dataGridView1->Rows[e->RowIndex]->Cells[5]->Value->ToString())].n_of_booking).ToString(),
						dataGridView1->Rows[e->RowIndex]->Cells[4]->Value->ToString()
				}));
			}
		}
	}
}
};
}
