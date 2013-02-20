#pragma once

#include "MyPriceComboBoxItem.h"
#include "MyBeep.h"

namespace FirstWinNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;

	/// <summary>
	/// Summary for PriceDialog
	/// </summary>
	public ref class PriceDialog : public System::Windows::Forms::Form
	{
	public:
		PriceDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_hasError = false;
			m_isCancelPressed = false;
			m_textForeColor = this->priceComboBox->ForeColor;
			m_currentCulture = gcnew CultureInfo("fr-FR");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PriceDialog()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::ErrorProvider^  errorProvider1;
	private: System::Windows::Forms::Button^  cancelButton;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::ComboBox^  priceComboBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  quantityTextBox;
	private: System::Windows::Forms::Label^  label7;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		bool m_hasError;
		bool m_isCancelPressed;
		Color m_textForeColor;
		CultureInfo^ m_currentCulture;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->priceComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->quantityTextBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(39, 112);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(27, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Prix:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(209, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"€";
			// 
			// okButton
			// 
			this->okButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->okButton->Location = System::Drawing::Point(34, 201);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 2;
			this->okButton->Text = L"Ok";
			this->okButton->UseVisualStyleBackColor = true;
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// cancelButton
			// 
			this->cancelButton->CausesValidation = false;
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(127, 201);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 3;
			this->cancelButton->Text = L"Annuler";
			this->cancelButton->UseVisualStyleBackColor = true;
			// 
			// priceComboBox
			// 
			this->priceComboBox->FormattingEnabled = true;
			this->priceComboBox->Location = System::Drawing::Point(72, 107);
			this->priceComboBox->Name = L"priceComboBox";
			this->priceComboBox->Size = System::Drawing::Size(121, 21);
			this->priceComboBox->TabIndex = 0;
			this->priceComboBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PriceDialog::priceComboBox_KeyDown);
			this->priceComboBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &PriceDialog::priceComboBox_Validating);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(45, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Code du Fabricant :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(50, 54);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(95, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Code du coupon : ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Navy;
			this->label5->Location = System::Drawing::Point(151, 24);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Navy;
			this->label6->Location = System::Drawing::Point(151, 54);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"label6";
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(40, 11);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(168, 77);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(13, 156);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(53, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Quantité :";
			// 
			// quantityTextBox
			// 
			this->quantityTextBox->Location = System::Drawing::Point(72, 153);
			this->quantityTextBox->Name = L"quantityTextBox";
			this->quantityTextBox->Size = System::Drawing::Size(100, 20);
			this->quantityTextBox->TabIndex = 1;
			this->quantityTextBox->Text = L"1";
			this->quantityTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PriceDialog::quantityTextBox_KeyDown);
			this->quantityTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &PriceDialog::quantityTextBox_Validating);
			// 
			// PriceDialog
			// 
			this->AcceptButton = this->okButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(244, 249);
			this->ControlBox = false;
			this->Controls->Add(this->quantityTextBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->priceComboBox);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"PriceDialog";
			this->Text = L"Entrer un prix";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PriceDialog::quantityTextBox_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:
		property String^ codeFabricant {
			void set( String^ newTxt ) {
				this->label5->Text = newTxt;
			}
		}

	public:
		property String^ codeCoupon {
			void set( String^ newTxt ) {
				this->label6->Text = newTxt;
			}
		}

	public:
		property String^ quantite {
			String^ get() {
				return this->quantityTextBox->Text;
			}
		}

	public: const String^ getPrice() {

		// check if the value has been entered or selected
		if ( this->priceComboBox->SelectedIndex > -1 ) {
			// a value has been selected from the list !!!
			MyPriceComboBoxItem^ lpItem =  ( MyPriceComboBoxItem^ ) this->priceComboBox->SelectedItem;
			//return ( Decimal::Parse( lpItem->value ) / 100 ).ToString( m_currentCulture );
			return lpItem->value;
		} else {
			// a value has been entered !!!
			String^ aTemp = this->priceComboBox->Text;
			aTemp = aTemp->Replace( '.', ',' );
			int aLength = aTemp->Length;
			int aIdx = aTemp->IndexOf( ',' );
			if (aIdx == -1) {
				// no comma found
				if ( aLength == 1 )
					return String::Concat( aTemp, "00" );
				if ( aLength == 2 )
					return String::Concat( aTemp, "01" );
			}
			if ( aIdx == 0 ) {
				// le prix commence par une decimale
				aTemp = aTemp->Insert( 0, "0" );
			}
			aTemp = aTemp->Replace( ",", "" );
			aLength = aTemp->Length;
			if ( aLength == 2 ) {
				// ex: 13
				return String::Concat( aTemp, "0" );
			}
			// ex: 10,35
			return aTemp;
		}
	}

	public: System::Void populatePriceComboBox( List<MyPriceComboBoxItem^>^ lpLstPrices ) {

		if ( lpLstPrices->Count == 0 ) {
			this->priceComboBox->Items->Clear();
		} else {
			for each ( MyPriceComboBoxItem^ t in lpLstPrices ) {
				this->priceComboBox->Items->Add( t );
			}
			this->priceComboBox->SelectedIndex = 0;
		}
	}

	protected: virtual bool ProcessCmdKey(Message% msg, Keys keyData) override {

		switch( keyData ) {
		case Keys::Escape:
			m_isCancelPressed = true;
			break;
		}     
		return __super::ProcessCmdKey( msg, keyData );
	}

/* ------------------------------------
 * Events functions
 * ------------------------------------ */
	private: System::Void priceComboBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		if ( m_isCancelPressed )
			return;

		if ( m_hasError ) {
			m_hasError = false;
			this->priceComboBox->ForeColor = m_textForeColor;
			this->priceComboBox->Text = nullptr;
		}

		System::Windows::Forms::Keys aKeyPressed = e->KeyCode;

		if ( aKeyPressed < Keys::D0 || aKeyPressed > Keys::D9 ) {
			// Determine whether the keystroke is a number from the keypad. 
			if ( aKeyPressed < Keys::NumPad0 || aKeyPressed > Keys::NumPad9 ) {
				// Determine whether the keystroke is a backspace. 
				if ( ( aKeyPressed != Keys::Back ) && ( aKeyPressed != Keys::Decimal ) && ( aKeyPressed != Keys::Oemcomma ) && ( aKeyPressed != Keys::Enter ) ) {
					Diagnostics::Debug::WriteLine("Not a number entered !!!");
					// don't display the keystroke
					e->SuppressKeyPress = true;
				}
			}
		}
	}

	/*
	 * Seul les digits de 0 a 9 sont acceptés
	 */
	private: System::Void quantityTextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		if ( m_isCancelPressed )
			return;

		if ( m_hasError ) {
			// set in the 'validating' function
			m_hasError = false;
			this->quantityTextBox->ForeColor = m_textForeColor;
			this->quantityTextBox->Text = "1";
			this->quantityTextBox->SelectAll();
		}

		System::Windows::Forms::Keys aKeyPressed = e->KeyCode;

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
	private: System::Void priceComboBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

		if ( m_isCancelPressed ) {
			this->errorProvider1->SetError( this->priceComboBox, "" );
			e->Cancel = false;
		} else if ( this->priceComboBox->Text->Length == 0 ) {
			m_hasError = true;
			// Cancel the event and select the text to be corrected by the user.
			e->Cancel = true;
			// display the wrong value in red, set the focus and select the value of the control
			this->priceComboBox->ForeColor = System::Drawing::Color::Red;
			this->priceComboBox->Select();
			// Set the ErrorProvider error with the text to display. 
			this->errorProvider1->SetError( this->priceComboBox, "Un prix doit être spécifié !" );
			MyBeep::beep();
		} else if ( this->priceComboBox->Text->Length > 10) {
			// peut se produire quand on scanne un coupon alors que le dialog est actif !!!!
			m_hasError = true;
			// Cancel the event and select the text to be corrected by the user.
			e->Cancel = true;
			// display the wrong value in red, set the focus and select the value of the control
			this->priceComboBox->ForeColor = System::Drawing::Color::Red;
			this->priceComboBox->Select();
			// Set the ErrorProvider error with the text to display. 
			this->errorProvider1->SetError( this->priceComboBox, "Le prix indiqué est beaucoup trop grand !" );
			MyBeep::beep();
		} else {
			this->errorProvider1->SetError( this->priceComboBox, "" );
			e->Cancel = false;
		}
	}

	private: System::Void quantityTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

		if ( m_isCancelPressed ) {
			this->errorProvider1->SetError( this->quantityTextBox, "" );
			e->Cancel = false;
		} else if ( this->quantityTextBox->Text->Length == 0 ) {
			MyBeep::beep();

			m_hasError = true;
			// Cancel the event and select the text to be corrected by the user.
			e->Cancel = true;

			// Set the ErrorProvider error with the text to display. 
			this->errorProvider1->SetError( this->quantityTextBox, "Un quantité doit être spécifiée !" );
		} else if ( this->quantityTextBox->Text->Length > 3 ) {
			MyBeep::beep();

			// peut se produire quand on scanne un coupon alors que le dialog est actif !!!!
			m_hasError = true;
			// Cancel the event and select the text to be corrected by the user.
			e->Cancel = true;

			// Set the ErrorProvider error with the text to display. 
			this->errorProvider1->SetError( this->quantityTextBox, "La quantité spécifiée est trop grande !" );
		} else {
			m_hasError = false;
			this->errorProvider1->SetError( this->quantityTextBox, "" );
			e->Cancel = false;
		}
	}

};
}
