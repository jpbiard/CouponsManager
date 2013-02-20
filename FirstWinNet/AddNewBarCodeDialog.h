#pragma once

#include "MyBeep.h"

namespace FirstWinNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddNewBarCodeDialog
	/// </summary>
	public ref class AddNewBarCodeDialog : public System::Windows::Forms::Form
	{
	public:
		AddNewBarCodeDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_textForeColor = this->quantiteTextBox->ForeColor;
			m_hasError = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddNewBarCodeDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  quantiteTextBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  ajouterButton;
	private: System::Windows::Forms::Button^  annulerButton;
	private: System::Windows::Forms::ErrorProvider^  errorProvider1;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Color m_textForeColor;
		bool m_hasError;
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->quantiteTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ajouterButton = (gcnew System::Windows::Forms::Button());
			this->annulerButton = (gcnew System::Windows::Forms::Button());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// quantiteTextBox
			// 
			this->quantiteTextBox->Location = System::Drawing::Point(161, 134);
			this->quantiteTextBox->Name = L"quantiteTextBox";
			this->quantiteTextBox->Size = System::Drawing::Size(48, 20);
			this->quantiteTextBox->TabIndex = 0;
			this->quantiteTextBox->Text = L"1";
			this->quantiteTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AddNewBarCodeDialog::quantiteText_KeyDown);
			this->quantiteTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AddNewBarCodeDialog::quantiteTextBox_Validating);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(58, 138);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Quantité a ajouter :";
			// 
			// ajouterButton
			// 
			this->ajouterButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->ajouterButton->Location = System::Drawing::Point(40, 172);
			this->ajouterButton->Name = L"ajouterButton";
			this->ajouterButton->Size = System::Drawing::Size(75, 23);
			this->ajouterButton->TabIndex = 2;
			this->ajouterButton->Text = L"Ajouter";
			this->ajouterButton->UseVisualStyleBackColor = true;
			// 
			// annulerButton
			// 
			this->annulerButton->CausesValidation = false;
			this->annulerButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->annulerButton->Location = System::Drawing::Point(172, 172);
			this->annulerButton->Name = L"annulerButton";
			this->annulerButton->Size = System::Drawing::Size(75, 23);
			this->annulerButton->TabIndex = 3;
			this->annulerButton->Text = L"Annuler";
			this->annulerButton->UseVisualStyleBackColor = true;
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(58, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Montant du coupon :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label3->Location = System::Drawing::Point(170, 84);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(72, 59);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(92, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Code du coupon :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(67, 33);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(97, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Code du fabricant :";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label6->Location = System::Drawing::Point(170, 59);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label7->Location = System::Drawing::Point(170, 33);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"label7";
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(47, 13);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 100);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			// 
			// AddNewBarCodeDialog
			// 
			this->AcceptButton = this->ajouterButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->annulerButton;
			this->ClientSize = System::Drawing::Size(299, 223);
			this->ControlBox = false;
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->annulerButton);
			this->Controls->Add(this->ajouterButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->quantiteTextBox);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AddNewBarCodeDialog";
			this->Text = L"Ajouter le nouveau Code Barre";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:
		property String^ quantite {
			String^ get() {
				return this->quantiteTextBox->Text;
			}
		}

	public:
		property String^ codeFabricant {
			void set( String^ newTxt ) {
				this->label7->Text = newTxt;
			}
		}

	public:
		property String^ codeCoupon {
			void set( String^ newTxt ) {
				this->label6->Text = newTxt;
			}
		}

	public:
		property String^ montantCoupon {
			void set( String^ newTxt ) {
				this->label3->Text = newTxt + " €";
			}
		}

/* ------------------------------------
 * Events functions
 * ------------------------------------ */

	/*
	 * Seul les digits de 0 a 9 sont acceptés
	 */
	private: System::Void quantiteText_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		System::Windows::Forms::Keys aKeyPressed = e->KeyCode;

		if ( m_hasError ) {
			// set in the 'validating' function
			m_hasError = false;
			this->quantiteTextBox->ForeColor = m_textForeColor;
			this->quantiteTextBox->Text = "1";
			this->quantiteTextBox->SelectAll();
		}

		if ( aKeyPressed == Keys::Cancel ) {
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Close();
		}

		if (aKeyPressed < Keys::D0 || aKeyPressed > Keys::D9 ) {
			// Determine whether the keystroke is a number from the keypad. 
			if ( aKeyPressed < Keys::NumPad0 || aKeyPressed > Keys::NumPad9 ) {
				// Determine whether the keystroke is a backspace. 
				if ( ( aKeyPressed != Keys::Back ) && ( aKeyPressed != Keys::Decimal ) ) {
					Diagnostics::Debug::WriteLine("Not a number entered !!!");
					// don't display the keystroke
					e->SuppressKeyPress = true;
				}
			}
		}
	}

/* ------------------------------------
 * Validating functions
 * ------------------------------------ */
	private: System::Void quantiteTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	
		if ( this->quantiteTextBox->Text->Length == 0 ) {
			MyBeep::beep();

			m_hasError = true;
			// Cancel the event and select the text to be corrected by the user.
			e->Cancel = true;

			// Set the ErrorProvider error with the text to display. 
			this->errorProvider1->SetError( this->quantiteTextBox, "Un quantité doit être spécifiée !" );
		} else if ( this->quantiteTextBox->Text->Length > 3 ) {
			MyBeep::beep();

			// peut se produire quand on scanne un coupon alors que le dialog est actif !!!!
			m_hasError = true;
			// Cancel the event and select the text to be corrected by the user.
			e->Cancel = true;

			// Set the ErrorProvider error with the text to display. 
			this->errorProvider1->SetError( this->quantiteTextBox, "La quantité spécifiée est trop grande !" );
		} else {
			m_hasError = false;
			this->errorProvider1->SetError( this->quantiteTextBox, "" );
			e->Cancel = false;
		}
	}
};
}
