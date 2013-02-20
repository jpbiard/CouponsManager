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
	/// Summary for CouponDialog
	/// </summary>
	public ref class CouponDialog : public System::Windows::Forms::Form
	{
	public:
		CouponDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->couponNomTextBox->Focus();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CouponDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  couponCodeTextBox;
	private: System::Windows::Forms::TextBox^  couponNomTextBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::Button^  cancelButton;
	private: System::Windows::Forms::RadioButton^  notSpecifiedRadioButton;
	private: System::Windows::Forms::RadioButton^  specifiedRadioButton;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::ErrorProvider^  errorProvider1;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->couponCodeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->couponNomTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->notSpecifiedRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->specifiedRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// couponCodeTextBox
			// 
			this->couponCodeTextBox->Location = System::Drawing::Point(154, 37);
			this->couponCodeTextBox->Name = L"couponCodeTextBox";
			this->couponCodeTextBox->ReadOnly = true;
			this->couponCodeTextBox->Size = System::Drawing::Size(100, 20);
			this->couponCodeTextBox->TabIndex = 0;
			this->couponCodeTextBox->TabStop = false;
			// 
			// couponNomTextBox
			// 
			this->couponNomTextBox->Location = System::Drawing::Point(102, 15);
			this->couponNomTextBox->Name = L"couponNomTextBox";
			this->couponNomTextBox->Size = System::Drawing::Size(215, 20);
			this->couponNomTextBox->TabIndex = 3;
			this->couponNomTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &CouponDialog::couponNomTextBox_Validating);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(58, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Code du coupon:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Nom du coupon:";
			// 
			// okButton
			// 
			this->okButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->okButton->Location = System::Drawing::Point(111, 178);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 4;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			// 
			// cancelButton
			// 
			this->cancelButton->CausesValidation = false;
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(215, 178);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 5;
			this->cancelButton->Text = L"Annuler";
			this->cancelButton->UseVisualStyleBackColor = true;
			// 
			// notSpecifiedRadioButton
			// 
			this->notSpecifiedRadioButton->AutoSize = true;
			this->notSpecifiedRadioButton->CausesValidation = false;
			this->notSpecifiedRadioButton->Location = System::Drawing::Point(64, 65);
			this->notSpecifiedRadioButton->Name = L"notSpecifiedRadioButton";
			this->notSpecifiedRadioButton->Size = System::Drawing::Size(82, 17);
			this->notSpecifiedRadioButton->TabIndex = 1;
			this->notSpecifiedRadioButton->TabStop = true;
			this->notSpecifiedRadioButton->Text = L"non spécifié";
			this->notSpecifiedRadioButton->UseVisualStyleBackColor = true;
			this->notSpecifiedRadioButton->Click += gcnew System::EventHandler(this, &CouponDialog::notSpecifiedRadioButton_Click);
			// 
			// specifiedRadioButton
			// 
			this->specifiedRadioButton->AutoSize = true;
			this->specifiedRadioButton->CausesValidation = false;
			this->specifiedRadioButton->Checked = true;
			this->specifiedRadioButton->Location = System::Drawing::Point(64, 88);
			this->specifiedRadioButton->Name = L"specifiedRadioButton";
			this->specifiedRadioButton->Size = System::Drawing::Size(61, 17);
			this->specifiedRadioButton->TabIndex = 2;
			this->specifiedRadioButton->TabStop = true;
			this->specifiedRadioButton->Text = L"spécifié";
			this->specifiedRadioButton->UseVisualStyleBackColor = true;
			this->specifiedRadioButton->Click += gcnew System::EventHandler(this, &CouponDialog::specifiedRadioButton_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->couponNomTextBox);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(52, 111);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(333, 51);
			this->panel1->TabIndex = 18;
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// CouponDialog
			// 
			this->AcceptButton = this->okButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(433, 223);
			this->ControlBox = false;
			this->Controls->Add(this->notSpecifiedRadioButton);
			this->Controls->Add(this->specifiedRadioButton);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->couponCodeTextBox);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"CouponDialog";
			this->Text = L"Spécifier un nom pour le coupon";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: 
		property String^ codeCoupon {
			void set( String^ newTxt ) {
				this->couponCodeTextBox->Text = newTxt;
			}
		}

	public:
		property String^ nomCoupon {
			String^ get() {
				return this->couponNomTextBox->Text;
			}
		}

	public:
		property bool isSpecified {
			bool get() {
				return this->specifiedRadioButton->Checked;
			}
		}

	protected: virtual bool ProcessCmdKey(Message% msg, Keys keyData) override {

		if ( this->specifiedRadioButton->Checked )
			return __super::ProcessCmdKey( msg, keyData );

		switch( keyData ) {
		case Keys::Up:
		case Keys::Down:
		case Keys::Enter:
		case Keys::Escape:
			return __super::ProcessCmdKey( msg, keyData );
			break;
		default:
			MyBeep::beepSystem( MyBeep::MessageBeepType::Error );
		}     

		return true;
	}

/* ------------------------------------
 * Events functions
 * ------------------------------------ */
	private: System::Void notSpecifiedRadioButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panel1->Enabled = false;
	}

	private: System::Void specifiedRadioButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panel1->Enabled = true;
		this->couponNomTextBox->Focus();
	}

/* ------------------------------------
 * Validating functions
 * ------------------------------------ */
	private: System::Void couponNomTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	
		if ( this->specifiedRadioButton->Checked ) {
			if ( this->couponNomTextBox->Text->Length == 0 ) {
				MyBeep::beep();

				// Cancel the event and select the text to be corrected by the user.
				e->Cancel = true;

				// Set the ErrorProvider error with the text to display. 
				this->errorProvider1->SetError( this->couponNomTextBox, "Un nom de coupon doit être spécifiée !" );
				return;
			}
		}
		this->errorProvider1->SetError( this->couponCodeTextBox, nullptr );
		e->Cancel = false;
	}

};
}
