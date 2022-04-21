#pragma once
#include "tree.h"
#include "avlTree.h"
#include "splayTree.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using std::string;

using std::vector;

using std::ofstream;

using std::cout;

using std::endl;

using std::max;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
#include <fstream>
using std::ofstream;

namespace CIS376CompareTreesTermProject {

	ofstream f;
	const string filename = "TreeLogFile.txt";

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

		}

	protected:
		tree* bst = new tree();
		tree* a = new avl();
		tree* spl = new splay();

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Insertbutton;
	private: System::Windows::Forms::Button^ Searchbutton;
	private: System::Windows::Forms::Button^ Deletebutton;
	private: System::Windows::Forms::TextBox^ InserttextBox;
	private: System::Windows::Forms::TextBox^ SearchtextBox;
	private: System::Windows::Forms::TextBox^ DeletetextBox;
	protected:






	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ AVLInsertlabel;
	private: System::Windows::Forms::Label^ AVLDeletelabel;


	private: System::Windows::Forms::Label^ AVLSearchlabel;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ BSTInsertlabel;
	private: System::Windows::Forms::Label^ BSTDeletelabel;


	private: System::Windows::Forms::Label^ BSTSearchlabel;

	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ SplayInsertlabel;
	private: System::Windows::Forms::Label^ SplaySearchlabel;
	private: System::Windows::Forms::Label^ SplayDeletelabel;




	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


		//search click
		//insert click
		//function for file - calls print to file
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Insertbutton = (gcnew System::Windows::Forms::Button());
			this->Searchbutton = (gcnew System::Windows::Forms::Button());
			this->Deletebutton = (gcnew System::Windows::Forms::Button());
			this->InserttextBox = (gcnew System::Windows::Forms::TextBox());
			this->SearchtextBox = (gcnew System::Windows::Forms::TextBox());
			this->DeletetextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->AVLDeletelabel = (gcnew System::Windows::Forms::Label());
			this->AVLSearchlabel = (gcnew System::Windows::Forms::Label());
			this->AVLInsertlabel = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->BSTDeletelabel = (gcnew System::Windows::Forms::Label());
			this->BSTSearchlabel = (gcnew System::Windows::Forms::Label());
			this->BSTInsertlabel = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->SplayDeletelabel = (gcnew System::Windows::Forms::Label());
			this->SplayInsertlabel = (gcnew System::Windows::Forms::Label());
			this->SplaySearchlabel = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// Insertbutton
			// 
			this->Insertbutton->Location = System::Drawing::Point(8, 222);
			this->Insertbutton->Margin = System::Windows::Forms::Padding(2);
			this->Insertbutton->Name = L"Insertbutton";
			this->Insertbutton->Size = System::Drawing::Size(103, 39);
			this->Insertbutton->TabIndex = 0;
			this->Insertbutton->Text = L"Insert";
			this->Insertbutton->UseVisualStyleBackColor = true;
			this->Insertbutton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// Searchbutton
			// 
			this->Searchbutton->Location = System::Drawing::Point(115, 222);
			this->Searchbutton->Margin = System::Windows::Forms::Padding(2);
			this->Searchbutton->Name = L"Searchbutton";
			this->Searchbutton->Size = System::Drawing::Size(103, 39);
			this->Searchbutton->TabIndex = 1;
			this->Searchbutton->Text = L"Search";
			this->Searchbutton->UseVisualStyleBackColor = true;
			this->Searchbutton->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// Deletebutton
			// 
			this->Deletebutton->Location = System::Drawing::Point(221, 222);
			this->Deletebutton->Margin = System::Windows::Forms::Padding(2);
			this->Deletebutton->Name = L"Deletebutton";
			this->Deletebutton->Size = System::Drawing::Size(103, 39);
			this->Deletebutton->TabIndex = 2;
			this->Deletebutton->Text = L"Delete";
			this->Deletebutton->UseVisualStyleBackColor = true;
			this->Deletebutton->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// InserttextBox
			// 
			this->InserttextBox->Location = System::Drawing::Point(8, 201);
			this->InserttextBox->Margin = System::Windows::Forms::Padding(2);
			this->InserttextBox->Name = L"InserttextBox";
			this->InserttextBox->Size = System::Drawing::Size(104, 20);
			this->InserttextBox->TabIndex = 3;
			// 
			// SearchtextBox
			// 
			this->SearchtextBox->Location = System::Drawing::Point(115, 201);
			this->SearchtextBox->Margin = System::Windows::Forms::Padding(2);
			this->SearchtextBox->Name = L"SearchtextBox";
			this->SearchtextBox->Size = System::Drawing::Size(104, 20);
			this->SearchtextBox->TabIndex = 4;
			// 
			// DeletetextBox
			// 
			this->DeletetextBox->Location = System::Drawing::Point(221, 201);
			this->DeletetextBox->Margin = System::Windows::Forms::Padding(2);
			this->DeletetextBox->Name = L"DeletetextBox";
			this->DeletetextBox->Size = System::Drawing::Size(104, 20);
			this->DeletetextBox->TabIndex = 5;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->AVLDeletelabel);
			this->groupBox1->Controls->Add(this->AVLSearchlabel);
			this->groupBox1->Controls->Add(this->AVLInsertlabel);
			this->groupBox1->Location = System::Drawing::Point(8, 36);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(103, 96);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"AVL Tree";
			// 
			// AVLDeletelabel
			// 
			this->AVLDeletelabel->AutoSize = true;
			this->AVLDeletelabel->Location = System::Drawing::Point(4, 54);
			this->AVLDeletelabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->AVLDeletelabel->Name = L"AVLDeletelabel";
			this->AVLDeletelabel->Size = System::Drawing::Size(41, 13);
			this->AVLDeletelabel->TabIndex = 9;
			this->AVLDeletelabel->Text = L"Delete:";
			// 
			// AVLSearchlabel
			// 
			this->AVLSearchlabel->AutoSize = true;
			this->AVLSearchlabel->Location = System::Drawing::Point(4, 41);
			this->AVLSearchlabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->AVLSearchlabel->Name = L"AVLSearchlabel";
			this->AVLSearchlabel->Size = System::Drawing::Size(44, 13);
			this->AVLSearchlabel->TabIndex = 8;
			this->AVLSearchlabel->Text = L"Search:";
			// 
			// AVLInsertlabel
			// 
			this->AVLInsertlabel->AutoSize = true;
			this->AVLInsertlabel->Location = System::Drawing::Point(4, 28);
			this->AVLInsertlabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->AVLInsertlabel->Name = L"AVLInsertlabel";
			this->AVLInsertlabel->Size = System::Drawing::Size(36, 13);
			this->AVLInsertlabel->TabIndex = 7;
			this->AVLInsertlabel->Text = L"Insert:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->BSTDeletelabel);
			this->groupBox2->Controls->Add(this->BSTSearchlabel);
			this->groupBox2->Controls->Add(this->BSTInsertlabel);
			this->groupBox2->Location = System::Drawing::Point(115, 36);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(103, 96);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"BST";
			// 
			// BSTDeletelabel
			// 
			this->BSTDeletelabel->AutoSize = true;
			this->BSTDeletelabel->Location = System::Drawing::Point(4, 54);
			this->BSTDeletelabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->BSTDeletelabel->Name = L"BSTDeletelabel";
			this->BSTDeletelabel->Size = System::Drawing::Size(41, 13);
			this->BSTDeletelabel->TabIndex = 2;
			this->BSTDeletelabel->Text = L"Delete:";
			// 
			// BSTSearchlabel
			// 
			this->BSTSearchlabel->AutoSize = true;
			this->BSTSearchlabel->Location = System::Drawing::Point(4, 41);
			this->BSTSearchlabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->BSTSearchlabel->Name = L"BSTSearchlabel";
			this->BSTSearchlabel->Size = System::Drawing::Size(44, 13);
			this->BSTSearchlabel->TabIndex = 1;
			this->BSTSearchlabel->Text = L"Search:";
			// 
			// BSTInsertlabel
			// 
			this->BSTInsertlabel->AutoSize = true;
			this->BSTInsertlabel->Location = System::Drawing::Point(4, 28);
			this->BSTInsertlabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->BSTInsertlabel->Name = L"BSTInsertlabel";
			this->BSTInsertlabel->Size = System::Drawing::Size(36, 13);
			this->BSTInsertlabel->TabIndex = 0;
			this->BSTInsertlabel->Text = L"Insert:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->SplayDeletelabel);
			this->groupBox3->Controls->Add(this->SplayInsertlabel);
			this->groupBox3->Controls->Add(this->SplaySearchlabel);
			this->groupBox3->Location = System::Drawing::Point(221, 36);
			this->groupBox3->Margin = System::Windows::Forms::Padding(2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(2);
			this->groupBox3->Size = System::Drawing::Size(103, 96);
			this->groupBox3->TabIndex = 8;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Splay";
			// 
			// SplayDeletelabel
			// 
			this->SplayDeletelabel->AutoSize = true;
			this->SplayDeletelabel->Location = System::Drawing::Point(4, 52);
			this->SplayDeletelabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SplayDeletelabel->Name = L"SplayDeletelabel";
			this->SplayDeletelabel->Size = System::Drawing::Size(41, 13);
			this->SplayDeletelabel->TabIndex = 10;
			this->SplayDeletelabel->Text = L"Delete:";
			// 
			// SplayInsertlabel
			// 
			this->SplayInsertlabel->AutoSize = true;
			this->SplayInsertlabel->Location = System::Drawing::Point(5, 25);
			this->SplayInsertlabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SplayInsertlabel->Name = L"SplayInsertlabel";
			this->SplayInsertlabel->Size = System::Drawing::Size(36, 13);
			this->SplayInsertlabel->TabIndex = 0;
			this->SplayInsertlabel->Text = L"Insert:";
			// 
			// SplaySearchlabel
			// 
			this->SplaySearchlabel->AutoSize = true;
			this->SplaySearchlabel->Location = System::Drawing::Point(4, 39);
			this->SplaySearchlabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SplaySearchlabel->Name = L"SplaySearchlabel";
			this->SplaySearchlabel->Size = System::Drawing::Size(44, 13);
			this->SplaySearchlabel->TabIndex = 9;
			this->SplaySearchlabel->Text = L"Search:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(329, 286);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->DeletetextBox);
			this->Controls->Add(this->SearchtextBox);
			this->Controls->Add(this->InserttextBox);
			this->Controls->Add(this->Deletebutton);
			this->Controls->Add(this->Searchbutton);
			this->Controls->Add(this->Insertbutton);
			this->Name = L"MyForm";
			this->Text = L"CompareTrees";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			int insertNum = 0;
			insertNum = Convert::ToInt32(InserttextBox->Text);
			a->insertNode(insertNum);
			spl->insertNode(insertNum);
			bst->insertNode(insertNum);
			AVLInsertlabel->Text = "Insert: " + System::Convert::ToString(a->getCountInserts());
			BSTInsertlabel->Text = "Insert: " + System::Convert::ToString(bst->getCountInserts());
			SplayInsertlabel->Text = "Insert: " + System::Convert::ToString(spl->getCountInserts());

			f.open(filename, std::ios_base::out);
			a->printTree(f);
			spl->printTree(f);
			bst->printTree(f);
			f.close();

		}
		catch(...)
		{
			InserttextBox->Text = "ERROR";
		}

		
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int insertNum = 0;

		try
		{
			insertNum = Convert::ToInt32(SearchtextBox->Text);
			bool find = false;
			a->searchNode(insertNum, find);
			spl->searchNode(insertNum, find);
			bst->searchNode(insertNum, find);
			AVLSearchlabel->Text = "Search: " + System::Convert::ToString(a->getCountSearches());
			BSTSearchlabel->Text = "Search: " + System::Convert::ToString(bst->getCountSearches());
			SplaySearchlabel->Text = "Search: " + System::Convert::ToString(spl->getCountSearches());

		}
		catch (...)
		{
			SearchtextBox->Text = "ERROR";
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		int insertNum = 0;
		
		try
		{
			insertNum = Convert::ToInt32(DeletetextBox->Text);
			a->deleteItem(insertNum);
			spl->deleteItem(insertNum);
			bst->deleteItem(insertNum);
			AVLDeletelabel->Text = "Delete: " + System::Convert::ToString(a->getCountDeletes());
			BSTDeletelabel->Text = "Delete: " + System::Convert::ToString(bst->getCountDeletes());
			SplayDeletelabel->Text = "Delete: " + System::Convert::ToString(spl->getCountDeletes());

			f.open(filename, std::ios_base::out);
			a->printTree(f);
			spl->printTree(f);
			bst->printTree(f);
			f.close();
		}
		catch (...)
		{
			DeletetextBox->Text = "ERROR";
		}
	}

};
}
