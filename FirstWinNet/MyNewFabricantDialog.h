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
	/// Summary for MyNewFabricantDialog
	/// </summary>
	public ref class MyNewFabricantDialog : public System::Windows::Forms::Form
	{
	public:
		MyNewFabricantDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			updateInfoRichTextBox();
			m_hasErrorNomFabricant = false;
			m_hasErrorNomCoupon = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyNewFabricantDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  codeFabricantTextBox;
	private: System::Windows::Forms::TextBox^  nomFabricantTextBox;

	private: System::Windows::Forms::TextBox^  codeCouponTextBox;
	private: System::Windows::Forms::TextBox^  nomCouponTextBox;
	private: System::Windows::Forms::Button^  cancelButton;
	private: System::Windows::Forms::RichTextBox^  infoRichTextBox;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  notSpecifiedRadioButton;
	private: System::Windows::Forms::RadioButton^  specifiedRadioButton;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::RadioButton^  notSpecifiedRadioButton1;
	private: System::Windows::Forms::RadioButton^  specifiedRadioButton2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::ErrorProvider^  errorProvider1;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		bool m_hasErrorNomFabricant;
		bool m_hasErrorNomCoupon;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->codeFabricantTextBox = (gcnew System::Windows::Forms::TextBox());
			this->nomFabricantTextBox = (gcnew System::Windows::Forms::TextBox());
			this->codeCouponTextBox = (gcnew System::Windows::Forms::TextBox());
			this->nomCouponTextBox = (gcnew System::Windows::Forms::TextBox());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->infoRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->specifiedRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->notSpecifiedRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->notSpecifiedRadioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->specifiedRadioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// okButton
			// 
			this->okButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->okButton->Location = System::Drawing::Point(170, 529);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(74, 23);
			this->okButton->TabIndex = 5;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(8, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Nom du fabricant:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(6, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(94, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Code du fabricant:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(11, 27);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Code du coupon:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(14, 52);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Nom du coupon:";
			// 
			// codeFabricantTextBox
			// 
			this->codeFabricantTextBox->Location = System::Drawing::Point(110, 17);
			this->codeFabricantTextBox->Name = L"codeFabricantTextBox";
			this->codeFabricantTextBox->ReadOnly = true;
			this->codeFabricantTextBox->Size = System::Drawing::Size(100, 20);
			this->codeFabricantTextBox->TabIndex = 5;
			this->codeFabricantTextBox->TabStop = false;
			// 
			// nomFabricantTextBox
			// 
			this->nomFabricantTextBox->Location = System::Drawing::Point(110, 48);
			this->nomFabricantTextBox->Name = L"nomFabricantTextBox";
			this->nomFabricantTextBox->ShortcutsEnabled = false;
			this->nomFabricantTextBox->Size = System::Drawing::Size(220, 20);
			this->nomFabricantTextBox->TabIndex = 12;
			this->nomFabricantTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MyNewFabricantDialog::nomFabricantTextBox_Validating);
			// 
			// codeCouponTextBox
			// 
			this->codeCouponTextBox->Location = System::Drawing::Point(110, 24);
			this->codeCouponTextBox->Name = L"codeCouponTextBox";
			this->codeCouponTextBox->ReadOnly = true;
			this->codeCouponTextBox->Size = System::Drawing::Size(100, 20);
			this->codeCouponTextBox->TabIndex = 7;
			this->codeCouponTextBox->TabStop = false;
			// 
			// nomCouponTextBox
			// 
			this->nomCouponTextBox->Location = System::Drawing::Point(110, 52);
			this->nomCouponTextBox->Name = L"nomCouponTextBox";
			this->nomCouponTextBox->ShortcutsEnabled = false;
			this->nomCouponTextBox->Size = System::Drawing::Size(220, 20);
			this->nomCouponTextBox->TabIndex = 13;
			this->nomCouponTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MyNewFabricantDialog::nomCouponTextBox_Validating);
			// 
			// cancelButton
			// 
			this->cancelButton->CausesValidation = false;
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(251, 529);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(74, 23);
			this->cancelButton->TabIndex = 6;
			this->cancelButton->Text = L"Annuler";
			this->cancelButton->UseVisualStyleBackColor = true;
			// 
			// infoRichTextBox
			// 
			this->infoRichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->infoRichTextBox->Location = System::Drawing::Point(13, 15);
			this->infoRichTextBox->Margin = System::Windows::Forms::Padding(13);
			this->infoRichTextBox->Name = L"infoRichTextBox";
			this->infoRichTextBox->ReadOnly = true;
			this->infoRichTextBox->Size = System::Drawing::Size(547, 93);
			this->infoRichTextBox->TabIndex = 10;
			this->infoRichTextBox->TabStop = false;
			this->infoRichTextBox->Text = L"";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->codeFabricantTextBox);
			this->groupBox1->Controls->Add(this->nomFabricantTextBox);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(28, 15);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(345, 82);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Fabricant";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->codeCouponTextBox);
			this->groupBox2->Controls->Add(this->nomCouponTextBox);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(28, 18);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(345, 91);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Coupon";
			// 
			// specifiedRadioButton
			// 
			this->specifiedRadioButton->AutoSize = true;
			this->specifiedRadioButton->Checked = true;
			this->specifiedRadioButton->Location = System::Drawing::Point(9, 31);
			this->specifiedRadioButton->Name = L"specifiedRadioButton";
			this->specifiedRadioButton->Size = System::Drawing::Size(61, 17);
			this->specifiedRadioButton->TabIndex = 2;
			this->specifiedRadioButton->TabStop = true;
			this->specifiedRadioButton->Text = L"&spécifié";
			this->specifiedRadioButton->UseVisualStyleBackColor = true;
			this->specifiedRadioButton->Click += gcnew System::EventHandler(this, &MyNewFabricantDialog::specifiedRadioButton_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Location = System::Drawing::Point(33, 184);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(399, 118);
			this->panel1->TabIndex = 14;
			// 
			// notSpecifiedRadioButton
			// 
			this->notSpecifiedRadioButton->AutoSize = true;
			this->notSpecifiedRadioButton->Location = System::Drawing::Point(9, 11);
			this->notSpecifiedRadioButton->Name = L"notSpecifiedRadioButton";
			this->notSpecifiedRadioButton->Size = System::Drawing::Size(82, 17);
			this->notSpecifiedRadioButton->TabIndex = 1;
			this->notSpecifiedRadioButton->Text = L"&non spécifié";
			this->notSpecifiedRadioButton->UseVisualStyleBackColor = true;
			this->notSpecifiedRadioButton->Click += gcnew System::EventHandler(this, &MyNewFabricantDialog::notSpecifiedRadioButton_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Location = System::Drawing::Point(33, 378);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(399, 131);
			this->panel2->TabIndex = 15;
			// 
			// notSpecifiedRadioButton1
			// 
			this->notSpecifiedRadioButton1->AutoSize = true;
			this->notSpecifiedRadioButton1->Location = System::Drawing::Point(9, 9);
			this->notSpecifiedRadioButton1->Name = L"notSpecifiedRadioButton1";
			this->notSpecifiedRadioButton1->Size = System::Drawing::Size(82, 17);
			this->notSpecifiedRadioButton1->TabIndex = 3;
			this->notSpecifiedRadioButton1->Text = L"n&on spécifié";
			this->notSpecifiedRadioButton1->UseVisualStyleBackColor = true;
			this->notSpecifiedRadioButton1->Click += gcnew System::EventHandler(this, &MyNewFabricantDialog::notSpecifiedRadioButton2_Click);
			// 
			// specifiedRadioButton2
			// 
			this->specifiedRadioButton2->AutoSize = true;
			this->specifiedRadioButton2->Checked = true;
			this->specifiedRadioButton2->Location = System::Drawing::Point(9, 27);
			this->specifiedRadioButton2->Name = L"specifiedRadioButton2";
			this->specifiedRadioButton2->Size = System::Drawing::Size(61, 17);
			this->specifiedRadioButton2->TabIndex = 4;
			this->specifiedRadioButton2->TabStop = true;
			this->specifiedRadioButton2->Text = L"s&pécifié";
			this->specifiedRadioButton2->UseVisualStyleBackColor = true;
			this->specifiedRadioButton2->Click += gcnew System::EventHandler(this, &MyNewFabricantDialog::specifiedRadioButton2_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->notSpecifiedRadioButton);
			this->groupBox3->Controls->Add(this->specifiedRadioButton);
			this->groupBox3->Location = System::Drawing::Point(24, 124);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(106, 54);
			this->groupBox3->TabIndex = 16;
			this->groupBox3->TabStop = false;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->notSpecifiedRadioButton1);
			this->groupBox4->Controls->Add(this->specifiedRadioButton2);
			this->groupBox4->Location = System::Drawing::Point(24, 320);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(106, 49);
			this->groupBox4->TabIndex = 17;
			this->groupBox4->TabStop = false;
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// MyNewFabricantDialog
			// 
			this->AcceptButton = this->okButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(562, 572);
			this->ControlBox = false;
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->infoRichTextBox);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox4);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyNewFabricantDialog";
			this->Text = L"Ajouter nouveau fabricant";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	public: 
		property String^ codeFabricant {
			void set( String^ newTxt ) {
				this->codeFabricantTextBox->Text = newTxt;
			}
		}

	public:
		property String^ nomFabricant {
			String^ get() {
				return this->nomFabricantTextBox->Text;
			}
		}

	public:
		property String^ codeCoupon {
			void set( String^ newTxt ) {
				this->codeCouponTextBox->Text = newTxt;
			}
		}

	public:
		property String^ nomCoupon {
			String^ get() {
				return this->nomCouponTextBox->Text;
			}
		}

	public:
		property bool isFabricantSpecified {
			bool get() {
				return this->specifiedRadioButton->Checked;
			}
		}

	public:
		property bool isCouponSpecified {
			bool get() {
				return this->specifiedRadioButton2->Checked;
			}
		}

	private: void updateInfoRichTextBox() {

		String^ aInfoRtf = "{\\rtf1\\ansi\\ansicpg1252\\deff0\\deflang2060{\\fonttbl{\\f0\\fnil Consolas;}{\\f1\\fnil\\fcharset0 Consolas;}{\\f2\\fnil\\fcharset0 Calibri;}{\\f3\\fnil\\fcharset2 Symbol;}}"
"{\\*\\generator Msftedit 5.41.21.2510;}\\viewkind4\\uc1\\pard\\sl240\\slmult1\\lang12\\f0\\fs16 Le \\lang2060\\b\\f1 F\\lang12\\f0 abricant \\lang2060\\b0\\f1 et le C\\b oupon \\b0 identifi\\'e9s \\lang12\\f0 dans le \\b Code \\f1\\'e0\\f0  barre \\b0 n\\lang2060\\f1 e sont \\lang12\\f0 pas encore connu de l'application.\\par"
"\\pard\\sl360\\slmult1\\lang2060\\f1 Pour le d\\'e9finir, suivez les instructions suivantes:\\par"
"\\pard{\\pntext\\f3\\'B7\\tab}{\\*\\pn\\pnlvlblt\\pnf3\\pnindent0{\\pntxtb\\'B7}}\\fi-360\\li720\\sl240\\slmult1\\lang12\\i\\f0 Veuillez entrer un nom pour ce Fabricant\\par"
"{\\pntext\\f3\\'B7\\tab}Veuillez aussi entrer un nom pour ce Coupon\\f2\\par}";

		this->infoRichTextBox->Rtf = aInfoRtf;
	}

/* ------------------------------------
 * Events functions
 * ------------------------------------ */
	private: System::Void specifiedRadioButton_Click(System::Object^  sender, System::EventArgs^  e) {
			this->panel1->Enabled = true;
			this->nomFabricantTextBox->Focus();
		 }
	
	private: System::Void notSpecifiedRadioButton_Click(System::Object^  sender, System::EventArgs^  e) {
			this->panel1->Enabled = false;
		 }

	private: System::Void notSpecifiedRadioButton2_Click(System::Object^  sender, System::EventArgs^  e) {
			this->panel2->Enabled = false;
		 }

	private: System::Void specifiedRadioButton2_Click(System::Object^  sender, System::EventArgs^  e) {
			this->panel2->Enabled = true;
			this->nomCouponTextBox->Focus();
		 }

/* ------------------------------------
 * Validating functions
 * ------------------------------------ */
	private: System::Void nomFabricantTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

		if ( this->isFabricantSpecified ) {
			if ( this->nomFabricantTextBox->TextLength == 0 ) {
				m_hasErrorNomFabricant = true;
				this->nomFabricantTextBox->Focus();

				MyBeep::beep();

				// Cancel the event and select the text to be corrected by the user.
				e->Cancel = true;

				// Set the ErrorProvider error with the text to display. 
				this->errorProvider1->SetError( this->nomFabricantTextBox, "Le nom du Fabricant ne peut pas être vide !" );

				return;
			}
		}

		this->errorProvider1->SetError( this->nomFabricantTextBox, "" );
		m_hasErrorNomFabricant = false;
		e->Cancel = false;
	}

	private: System::Void nomCouponTextBox_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

		if ( this->isCouponSpecified ) {
			if ( this->codeCouponTextBox->TextLength == 0 ) {
				m_hasErrorNomCoupon = true;
				this->nomCouponTextBox->Focus();

				MyBeep::beep();

				// Cancel the event and select the text to be corrected by the user.
				e->Cancel = true;

				// Set the ErrorProvider error with the text to display. 
				this->errorProvider1->SetError( this->codeCouponTextBox, "Le nom du Coupon ne peut pas être vide !" );

				return;
			}
		}

		this->errorProvider1->SetError( this->codeCouponTextBox, "" );
		m_hasErrorNomCoupon = false;
		e->Cancel = false;
	}

};
}
