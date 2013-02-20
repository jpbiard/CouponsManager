#pragma once

#include "MyXmlWriter.h"

namespace FirstWinNet {

	using namespace System;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Xml;

	/// <summary>
	/// Summary for SelectEmptyFileDialog
	/// </summary>
	public ref class SelectEmptyFileDialog : public System::Windows::Forms::Form
	{
	public:
		SelectEmptyFileDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			lpSelectedFileName = nullptr;
			this->folderTextBox->Text = Environment::GetFolderPath( Environment::SpecialFolder::Personal );
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SelectEmptyFileDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog;
	private: System::Windows::Forms::TextBox^  fileNameTextBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  browserButton;
	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::Button^  cancelButton;
	private: System::Windows::Forms::TextBox^  folderTextBox;
	private: System::Windows::Forms::Label^  label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->folderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->fileNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->browserButton = (gcnew System::Windows::Forms::Button());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->folderTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// folderBrowserDialog
			// 
			this->folderBrowserDialog->RootFolder = System::Environment::SpecialFolder::MyComputer;
			this->folderBrowserDialog->SelectedPath = L"C:\\Users\\jp\\Documents";
			// 
			// fileNameTextBox
			// 
			this->fileNameTextBox->Location = System::Drawing::Point(114, 62);
			this->fileNameTextBox->Name = L"fileNameTextBox";
			this->fileNameTextBox->Size = System::Drawing::Size(186, 20);
			this->fileNameTextBox->TabIndex = 0;
			this->fileNameTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SelectEmptyFileDialog::fileNameTextBox_KeyDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 66);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Nom du fichier:";
			// 
			// browserButton
			// 
			this->browserButton->Location = System::Drawing::Point(413, 27);
			this->browserButton->Name = L"browserButton";
			this->browserButton->Size = System::Drawing::Size(75, 23);
			this->browserButton->TabIndex = 2;
			this->browserButton->Text = L"Parcourir";
			this->browserButton->UseVisualStyleBackColor = true;
			this->browserButton->Click += gcnew System::EventHandler(this, &SelectEmptyFileDialog::browserButton_Click);
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(147, 141);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 3;
			this->okButton->Text = L"Ok";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &SelectEmptyFileDialog::okButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(272, 141);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 4;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			// 
			// folderTextBox
			// 
			this->folderTextBox->Location = System::Drawing::Point(114, 30);
			this->folderTextBox->Name = L"folderTextBox";
			this->folderTextBox->ReadOnly = true;
			this->folderTextBox->Size = System::Drawing::Size(290, 20);
			this->folderTextBox->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(49, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Répertoire:";
			// 
			// SelectEmptyFileDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(526, 200);
			this->ControlBox = false;
			this->Controls->Add(this->label2);
			this->Controls->Add(this->folderTextBox);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->browserButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->fileNameTextBox);
			this->Name = L"SelectEmptyFileDialog";
			this->Text = L"Fichier de sauvegarde";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: String^ lpSelectedFileName;

	private: System::Void browserButton_Click(System::Object^  sender, System::EventArgs^  e) {

			this->folderBrowserDialog->Description = "Choisissez le répertoire ou sera sauvegardé le fichier";
			//this->folderBrowserDialog->RootFolder = Environment::SpecialFolder::Personal;

			if ( this->folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK ) {
				this->folderTextBox->Text = this->folderBrowserDialog->SelectedPath;
			}
			// set the cursor at the end of the Text box
			this->fileNameTextBox->Focus();
			this->fileNameTextBox->SelectionStart = this->fileNameTextBox->TextLength;
			this->fileNameTextBox->SelectionLength = 0;
	}

	private: System::Void okButton_Click(System::Object^  sender, System::EventArgs^  e) {

		// creer le fichier
		FileStream^ lpFileStream = nullptr;

		// check filename not empty
		if ( this->fileNameTextBox->Text->Length == 0 ) {
			MessageBox::Show( "Le nom du fichier est vide !",
				"Nom du fichier de sauvegarde", MessageBoxButtons::OK,
				MessageBoxIcon::Error );
			this->lpSelectedFileName = nullptr;
			this->fileNameTextBox->Focus();
			return;
		}

		// verifier l'extension du fichier
		if ( ! this->fileNameTextBox->Text->EndsWith( ".xml" ) ) {
			this->fileNameTextBox->Text += ".xml";
		}

		try {
			lpFileStream = gcnew FileStream( this->folderTextBox->Text + "\\" + this->fileNameTextBox->Text, System::IO::FileMode::CreateNew );

			MyXmlWriter^ lpXmlWriter = gcnew MyXmlWriter();
			lpXmlWriter->SaveFabricantsList(lpFileStream);

			this->lpSelectedFileName = this->folderTextBox->Text + "\\" + this->fileNameTextBox->Text;
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			// fermer le dialog
			this->Close();
		} catch (Exception^ lpEx) {
			MessageBox::Show( lpEx->Message,
				"Nom du fichier de sauvegarde", MessageBoxButtons::OK,
				MessageBoxIcon::Error );
			this->lpSelectedFileName = nullptr;
		} finally {
			if ( lpFileStream != nullptr ) lpFileStream->Close();
		}

	}

	public: String^ getSelectedFileName() {

		return this->lpSelectedFileName;
	}

	private: System::Void fileNameTextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		if ( e->KeyCode == Keys::Return ) {
			// fermer le dialog
			 this->okButton->PerformClick();
		}
	 }

};
}
