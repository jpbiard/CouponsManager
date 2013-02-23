#define DEBUG

#pragma once

#include "MyXmlParser.h"
#include "MyCodeBar.h"
#include "MyFabricant.h"
#include "MyTomCoFabricant.h"
#include "MyCoupon.h"
#include "MyNewFabricantDialog.h"
#include "AddNewBarCodeDialog.h"
#include "SelectEmptyFileDialog.h"
#include "MyManualCouponForm.h"
#include "PriceDialog.h"
#include "CouponDialog.h"
#include "MyXmlWriter.h"
#include "MyPriceComboBoxItem.h"
#include "MyBeep.h"

#define FABRICANT_INCONNU "inconnu"
#define COUPON_INCONNU "inconnu"

namespace FirstWinNet {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Xml;
	using namespace System::Globalization;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			// InitializeApplication();
			m_actionId = -1;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  addedTextBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  addedAmountTextBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  addedArticleTextBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::ComponentModel::IContainer^  components;






	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  grandTotalTextBox;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  saveToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  printToolStripButton;
	private: System::Windows::Forms::TextBox^  couponsTotalBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripButton^  manualCouponStripButton;


	private:
		/// <summary>
		/// Required designer variable.
		List<MyFabricant^>^ m_fabricantsList;
		String^ m_outputFileName;
		Boolean^ m_changesDone;
		String^ m_lastSaveDate;
		CultureInfo^ m_lpcurrentCulture;
	private: System::Windows::Forms::ListView^  couponsListView;
	private: System::Windows::Forms::ColumnHeader^  product;
	private: System::Windows::Forms::ColumnHeader^  amount;
	private: System::Windows::Forms::ColumnHeader^  quantity;
	private: System::Windows::Forms::ColumnHeader^  total;
	private: System::Windows::Forms::ColumnHeader^  code;
	private: System::Windows::Forms::TextBox^  codeBarTextBox;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::ToolStripButton^  autoCouponStripButton;

			 int m_actionId;
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->addedTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->addedAmountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->addedArticleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->grandTotalTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->saveToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->printToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->autoCouponStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->manualCouponStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->couponsTotalBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->couponsListView = (gcnew System::Windows::Forms::ListView());
			this->product = (gcnew System::Windows::Forms::ColumnHeader());
			this->amount = (gcnew System::Windows::Forms::ColumnHeader());
			this->quantity = (gcnew System::Windows::Forms::ColumnHeader());
			this->total = (gcnew System::Windows::Forms::ColumnHeader());
			this->code = (gcnew System::Windows::Forms::ColumnHeader());
			this->codeBarTextBox = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->toolStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 403);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Entrer le code barre:";
			// 
			// addedTextBox
			// 
			this->addedTextBox->Location = System::Drawing::Point(16, 349);
			this->addedTextBox->Name = L"addedTextBox";
			this->addedTextBox->ReadOnly = true;
			this->addedTextBox->Size = System::Drawing::Size(216, 20);
			this->addedTextBox->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 333);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Fournisseur";
			// 
			// addedAmountTextBox
			// 
			this->addedAmountTextBox->Location = System::Drawing::Point(237, 349);
			this->addedAmountTextBox->Name = L"addedAmountTextBox";
			this->addedAmountTextBox->ReadOnly = true;
			this->addedAmountTextBox->Size = System::Drawing::Size(46, 20);
			this->addedAmountTextBox->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(234, 333);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Montant";
			// 
			// addedArticleTextBox
			// 
			this->addedArticleTextBox->Location = System::Drawing::Point(317, 349);
			this->addedArticleTextBox->Name = L"addedArticleTextBox";
			this->addedArticleTextBox->ReadOnly = true;
			this->addedArticleTextBox->Size = System::Drawing::Size(99, 20);
			this->addedArticleTextBox->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(314, 333);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Code Article";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(289, 352);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"€";
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(7, 311);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(436, 77);
			this->groupBox1->TabIndex = 15;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Dernier code barre entré";
			// 
			// grandTotalTextBox
			// 
			this->grandTotalTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->grandTotalTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->grandTotalTextBox->Location = System::Drawing::Point(428, 246);
			this->grandTotalTextBox->Name = L"grandTotalTextBox";
			this->grandTotalTextBox->ReadOnly = true;
			this->grandTotalTextBox->Size = System::Drawing::Size(154, 20);
			this->grandTotalTextBox->TabIndex = 16;
			this->grandTotalTextBox->TabStop = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(358, 249);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(66, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Grand Total:";
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->saveToolStripButton, 
				this->printToolStripButton, this->autoCouponStripButton, this->manualCouponStripButton});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(594, 25);
			this->toolStrip1->TabIndex = 18;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// saveToolStripButton
			// 
			this->saveToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->saveToolStripButton->Enabled = false;
			this->saveToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"saveToolStripButton.Image")));
			this->saveToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->saveToolStripButton->Name = L"saveToolStripButton";
			this->saveToolStripButton->Size = System::Drawing::Size(23, 22);
			this->saveToolStripButton->Text = L"&Save";
			this->saveToolStripButton->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			// 
			// printToolStripButton
			// 
			this->printToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->printToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"printToolStripButton.Image")));
			this->printToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->printToolStripButton->Name = L"printToolStripButton";
			this->printToolStripButton->Size = System::Drawing::Size(23, 22);
			this->printToolStripButton->Text = L"&Print";
			// 
			// autoCouponStripButton
			// 
			this->autoCouponStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->autoCouponStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"autoCouponStripButton.Image")));
			this->autoCouponStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->autoCouponStripButton->Name = L"autoCouponStripButton";
			this->autoCouponStripButton->Size = System::Drawing::Size(139, 22);
			this->autoCouponStripButton->Text = L"Coupon avec CodeBarre";
			this->autoCouponStripButton->Click += gcnew System::EventHandler(this, &Form1::autoCouponStripButton_Click);
			// 
			// manualCouponStripButton
			// 
			this->manualCouponStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->manualCouponStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"manualCouponStripButton.Image")));
			this->manualCouponStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->manualCouponStripButton->Name = L"manualCouponStripButton";
			this->manualCouponStripButton->Size = System::Drawing::Size(126, 22);
			this->manualCouponStripButton->Text = L"Coupon sans Barcode";
			this->manualCouponStripButton->Click += gcnew System::EventHandler(this, &Form1::manualCouponStripButton_Click);
			// 
			// couponsTotalBox
			// 
			this->couponsTotalBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->couponsTotalBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->couponsTotalBox->Location = System::Drawing::Point(428, 280);
			this->couponsTotalBox->Name = L"couponsTotalBox";
			this->couponsTotalBox->ReadOnly = true;
			this->couponsTotalBox->Size = System::Drawing::Size(154, 20);
			this->couponsTotalBox->TabIndex = 19;
			this->couponsTotalBox->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(299, 283);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(125, 13);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Nbr coupons enregistrés:";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripStatusLabel1, 
				this->toolStripStatusLabel2});
			this->statusStrip1->Location = System::Drawing::Point(0, 460);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(594, 22);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 21;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripStatusLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->toolStripStatusLabel1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(461, 17);
			this->toolStripStatusLabel1->Spring = true;
			this->toolStripStatusLabel1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripStatusLabel2->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(118, 17);
			this->toolStripStatusLabel2->Text = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// couponsListView
			// 
			this->couponsListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {this->product, this->amount, 
				this->quantity, this->total, this->code});
			this->couponsListView->GridLines = true;
			this->couponsListView->Location = System::Drawing::Point(1, 4);
			this->couponsListView->Name = L"couponsListView";
			this->couponsListView->Size = System::Drawing::Size(594, 213);
			this->couponsListView->TabIndex = 12;
			this->couponsListView->UseCompatibleStateImageBehavior = false;
			this->couponsListView->View = System::Windows::Forms::View::Details;
			// 
			// product
			// 
			this->product->Text = L"Coupon";
			// 
			// amount
			// 
			this->amount->Text = L"Montant";
			this->amount->Width = 86;
			// 
			// quantity
			// 
			this->quantity->Text = L"Qté";
			this->quantity->Width = 101;
			// 
			// total
			// 
			this->total->Text = L"Total";
			// 
			// code
			// 
			this->code->Text = L"Code";
			// 
			// codeBarTextBox
			// 
			this->codeBarTextBox->Location = System::Drawing::Point(118, 400);
			this->codeBarTextBox->Name = L"codeBarTextBox";
			this->codeBarTextBox->Size = System::Drawing::Size(219, 20);
			this->codeBarTextBox->TabIndex = 2;
			this->codeBarTextBox->Enter += gcnew System::EventHandler(this, &Form1::barCodeText_Enter);
			this->codeBarTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::barCodeText_KeyDown);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->codeBarTextBox);
			this->panel1->Controls->Add(this->couponsListView);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->couponsTotalBox);
			this->panel1->Controls->Add(this->grandTotalTextBox);
			this->panel1->Controls->Add(this->addedTextBox);
			this->panel1->Controls->Add(this->addedArticleTextBox);
			this->panel1->Controls->Add(this->addedAmountTextBox);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Location = System::Drawing::Point(-1, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(595, 433);
			this->panel1->TabIndex = 22;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(594, 482);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Gestionnaire de coupons";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::form_load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void InitializeApplication(void) {

		if (this->m_fabricantsList != nullptr) {
			this->m_fabricantsList->Clear();
			delete this->m_fabricantsList;
		}
		this->m_fabricantsList = gcnew List<MyFabricant^>(50);
		this->m_outputFileName = nullptr;
		this->m_changesDone = false;
		this->grandTotalTextBox->Clear();
		this->couponsTotalBox->Clear();
		this->couponsListView->Items->Clear();
		this->couponsListView->Groups->Clear();
		this->codeBarTextBox->Clear();
		this->moveCursorToEnd();
		this->toolStripStatusLabel1->Text = "";
		this->toolStripStatusLabel2->Text = "";
		this->saveToolStripButton->Enabled = false;
		// use french number display
		m_lpcurrentCulture = gcnew CultureInfo("fr-FR");
	}

	public:
		property int actionId {
			void set( int value ) {
				m_actionId = value;
			}
		}

	/*
	 * Event handler: when a new key is entered in the BarCodeTextBox
	 */
	private: System::Void barCodeText_KeyDown( System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e ) {

		bool isOk;
		System::Windows::Forms::Keys aKeyPressed = e->KeyCode;

		//Diagnostics::Debug::WriteLine(aKeyPressed);

		if ( aKeyPressed == Keys::Return ) {
			// a new CodeBar is ready
			MyCodeBar^ lpNewCodeBar = nullptr;
			String^ lpQuantite = nullptr;

			try {
				// create CodeBar object (the codebar is validated)
				lpNewCodeBar = gcnew MyCodeBar( this->codeBarTextBox->Text );
				isOk = true;

				// check for an amount zero
				if ( lpNewCodeBar->montantCoupon->CompareTo( "000" ) == 0 )  {
					// the user must enter a price !
					MyBeep::beepWarn();

					PriceDialog^ lpPriceDialog = gcnew PriceDialog();
					lpPriceDialog->codeFabricant = const_cast<String^>( lpNewCodeBar->codeFabricant );
					lpPriceDialog->codeCoupon = const_cast<String^>( lpNewCodeBar->codeCoupon );
					lpPriceDialog->populatePriceComboBox( this->populatePriceComboBox( lpNewCodeBar ) );
					lpPriceDialog->ShowDialog( this );
					
					if ( lpPriceDialog->DialogResult == System::Windows::Forms::DialogResult::OK ) {
						// get the price (remove the ',' from the price entered) and save it in the CodeBar object
						lpNewCodeBar->montantCoupon = const_cast<String^>( lpPriceDialog->getPrice() );
						lpQuantite = lpPriceDialog->quantite;
					} else {
						// when 'Cancel' is pressed
						isOk = false;
					}

					lpPriceDialog->Close();
					delete lpPriceDialog;
				}
				
				if ( isOk ) {
					// show the AddNewBarCodeDialog
					// permet de spécifier la quantite
					if ( lpQuantite == nullptr ) {
						AddNewBarCodeDialog^ lpAddNewBarCodeDialog = gcnew AddNewBarCodeDialog();
						lpAddNewBarCodeDialog->codeFabricant = const_cast<String^>( lpNewCodeBar->codeFabricant );
						lpAddNewBarCodeDialog->codeCoupon = const_cast<String^>( lpNewCodeBar->codeCoupon );
						lpAddNewBarCodeDialog->montantCoupon = lpNewCodeBar->montantDecimalCoupon->ToString( m_lpcurrentCulture );
						lpAddNewBarCodeDialog->ShowDialog( this );

						if ( lpAddNewBarCodeDialog->DialogResult == System::Windows::Forms::DialogResult::OK ) {
							lpQuantite = lpAddNewBarCodeDialog->quantite;
						} else {
							// when 'Cancel' is pressed
							isOk = false;
						}

						// close dialog
						lpAddNewBarCodeDialog->Close();
						delete lpAddNewBarCodeDialog;
					}
				}

				if ( isOk ) {
					// update the 'Fabricant' List
					this->showAddedCoupon( lpNewCodeBar );
					this->updateFabricantsList( lpNewCodeBar, lpQuantite );
					this->updateUnknownFabricants();
					this->showListView();
					// highlight the new ListView item
					this->highlightAddedCoupon(lpNewCodeBar);
					this->codeBarTextBox->Focus();
					/* TODO: implement the following in order to improve the ListView performance
					this->updateListView( lpNewCodeBar, lpAddNewBarCodeDialogDialog->getQuantite() );
					*/
				}	

			} catch ( Exception^ lpEx ) {
				// something wrong with BarCode
				MessageBox::Show( lpEx->Message,
					"Gestionnaire de coupons", MessageBoxButtons::OK,
					MessageBoxIcon::Error );
			}
			// clear the Barcode text
			this->codeBarTextBox->Clear();
		} else if (aKeyPressed < Keys::D0 || aKeyPressed > Keys::D9 ) {
			// Determine whether the keystroke is a number from the keypad.
			if ( aKeyPressed < Keys::NumPad0 || aKeyPressed > Keys::NumPad9 ) {
				// Determine whether the keystroke is a backspace.
				if ( aKeyPressed != Keys::Back ) {
					Diagnostics::Debug::WriteLine("Not a number entered !!!");
					// don't display the keystroke
					e->SuppressKeyPress = true;
				}
			}
		}
	}

	private: List<MyPriceComboBoxItem^>^ populatePriceComboBox(MyCodeBar^ lpCodeBar) {
		List<MyPriceComboBoxItem^>^ lstItems = gcnew List<MyPriceComboBoxItem^>(10);

		for each ( MyFabricant^ s in this->m_fabricantsList ) {
			if ( s->compareToCode( lpCodeBar ) ) {
				// same fabricant !!!
				List<MyCoupon^>^ lpCouponsList = s->couponsList;
				for each ( MyCoupon^ t in lpCouponsList ) {
					if (t->code->CompareTo( const_cast<String^>( lpCodeBar->codeCoupon ) ) == 0 ) {
						// same code coupon !!!
						MyPriceComboBoxItem^ aItem = gcnew MyPriceComboBoxItem( t->quantite, t->montantRaw );
						lstItems->Add( aItem );
					}
				}
			}
		}

		lstItems->Sort(gcnew Comparison<MyPriceComboBoxItem^>(MyPriceComboBoxItem::CompareItemsByCount));
		lstItems->Reverse();

		return lstItems;
	}

	private: System::Void highlightAddedCoupon(MyCodeBar^ theAddedCodeBar) {
		for each ( ListViewItem^ i in this->couponsListView->Items ) {
			if ( ( ( String^ ) i->Tag )->CompareTo( theAddedCodeBar->codeBarTag ) == 0 ) {
				this->couponsListView->Focus();
				this->couponsListView->SelectedItems->Clear();
				this->couponsListView->EnsureVisible( i->Index );
				i->Selected = true;
				i->Focused = true;
				i->BackColor = Color::Yellow;
				return;
			}
		}
	}

	private: System::Void showAddedCoupon(MyCodeBar^ theCodeBar) {
		this->addedTextBox->Text = const_cast<String^>( theCodeBar->codeFabricant );
		this->addedAmountTextBox->Text = theCodeBar->montantDecimalCoupon->ToString("F2")->Replace( ".", "," );
		this->addedArticleTextBox->Text = const_cast<String^>( theCodeBar->codeCoupon );
		this->codeBarTextBox->Clear();
		this->moveCursorToEnd();
	}

	private: System::Void barCodeText_Enter(System::Object^  sender, System::EventArgs^  e) {
		this->moveCursorToEnd();
	}

	private: System::Void moveCursorToEnd() {
		this->codeBarTextBox->SelectionStart = this->codeBarTextBox->TextLength ;
		this->codeBarTextBox->SelectionLength = 0;
	}

	/*
	 * showListView
	 * shows the ListView control with the data in FabricantsList
	 * !! si un Fabricant ne contient aucun coupon, il ne sera pas montre !!
	 */
	private: System::Void showListView() {
		/* NOTE: implementer quelque chose de plus performant que d'effacer
		tout le tableau !!!!
		Utiliser par exemple: ListViewItemCollection
		*/
		this->couponsListView->Items->Clear();
		this->couponsListView->Groups->Clear();

		Decimal aGrandTotal = 0;
		Decimal aCouponTotal = 0;
		int aCouponsQty = 0;

		for each ( MyFabricant^ s in this->m_fabricantsList ) {
			Diagnostics::Debug::WriteLine( "Fabricant: " + s->nom );
			ListViewGroup^ lpListViewGroup = gcnew ListViewGroup( s->code, s->nom + " (code: " + s->code + ")" );
			this->couponsListView->Groups->Add( lpListViewGroup );

			List<MyCoupon^>^ lpCouponsList = s->couponsList;
			array<ListViewItem^>^ lppItems = gcnew array<ListViewItem^>(lpCouponsList->Count);

			int iCount = 0;
			for each ( MyCoupon^ t in lpCouponsList ) {
				aCouponTotal = t->total;
				ListViewItem^ lpItem = gcnew ListViewItem( t->nom, lpListViewGroup );

				array<String^>^ strArray = { t->montant , t->quantite, ( aCouponTotal / 100 ).ToString(this->m_lpcurrentCulture), t->code };

				lpItem->SubItems->AddRange( strArray );
				lpItem->Tag = t->tag;

				lppItems[iCount++] = lpItem;

				// Mettre a jour le total
				aGrandTotal = Decimal::Add ( aGrandTotal, aCouponTotal );

				// Mettre à jour le nombre de coupons
				aCouponsQty += t->quantiteInt;
			}

			// Add the items to the ListView.
			this->couponsListView->Items->AddRange( lppItems );

		}

		this->grandTotalTextBox->Text = ( aGrandTotal / 100 ).ToString(this->m_lpcurrentCulture);
		this->couponsTotalBox->Text = ( gcnew UInt32( aCouponsQty ) )->ToString();
	}

	/*
	 * update all 'unknown' fabricant with existing fabricant
	 */
	private: System::Void updateUnknownFabricants( ) {

		int* lpArrayFabricants = new int[m_fabricantsList->Count];
		int aIdx = 0;
		bool isFound;

		for each ( MyFabricant^ s in this->m_fabricantsList ) {
			if ( s->isUnknown ) {
				isFound = false;
				for each ( MyFabricant^ t in this->m_fabricantsList ) {
					if ( ( ! t->isUnknown ) && ( t->code->CompareTo( s->code ) == 0 ) ) {
						// migrer tous les coupons vers ce fabriquant connu
						for each ( MyCoupon^ c in s->couponsList ) {
							for each ( MyCoupon^ d in t->couponsList ) {
								if ( ( d->code->CompareTo( c->code ) == 0 ) && ( d->montantRaw->CompareTo( c->montantRaw ) == 0 ) ) {
									// tout est identique (code + montant)
									d->addToQuantite( 1 );
									isFound = true;
									break;
								}
							}
							// un coupon identique n'a pas été trouvé
							t->addOneCoupon( c );
							isFound = true;
						}
					}
				}
				if ( isFound )
					lpArrayFabricants[aIdx++] = m_fabricantsList->IndexOf( s );
			}
		}

		for ( int i = 0; i < aIdx; i++ ) {
			m_fabricantsList->RemoveAt( lpArrayFabricants[i] );
		}
		delete [] lpArrayFabricants;
	}

	/*
	 * updateFabricantsList
	 */
	private: System::Void updateFabricantsList( MyCodeBar^ lpNewCodeBar, String^ lpQuantite ) {

		String^ nomCoupon;
		this->m_changesDone = true;
		this->saveToolStripButton->Enabled = true;

		// vérifier si le fabricant est déja enregistre
		for each ( MyFabricant^ s in this->m_fabricantsList ) {
			if ( s->compareTo( lpNewCodeBar ) ) {
				// le fabricant existe deja, verifier le coupon
				nomCoupon = nullptr;
				for each ( MyCoupon^ t in s->couponsList ) {
					if ( t->code->CompareTo( lpNewCodeBar->codeCoupon ) == 0 ) {
						// même code coupon
						nomCoupon = t->nom;
						if ( t->montantRaw->CompareTo( lpNewCodeBar->montantCoupon ) == 0 ) {
							// même code coupon et même montant: incrementer la quantite
							t->addToQuantite( Int32::Parse( lpQuantite ) );
							return;
						}
					}
				}
				if ( nomCoupon != nullptr ) {
					// Code est identique mais montant différent: créer un nouveau coupon pour ce fabricant
					s->addOneCoupon( nomCoupon, lpNewCodeBar->codeCoupon, lpNewCodeBar->montantCoupon, lpQuantite, lpNewCodeBar->codeBarTag );
					return;
				}
				// le code coupon n'est pas encore associé a ce fabricant
				// beep !!!
				MyBeep::beep();
				CouponDialog^ lpCouponDialog = gcnew CouponDialog();
				lpCouponDialog->codeCoupon = lpNewCodeBar->codeCoupon;
				lpCouponDialog->ShowDialog( this );
				if ( lpCouponDialog->DialogResult == System::Windows::Forms::DialogResult::OK ) {
					if ( lpCouponDialog->isSpecified ) {
						s->addOneCoupon( lpCouponDialog->nomCoupon, lpNewCodeBar->codeCoupon, lpNewCodeBar->montantCoupon, lpQuantite, lpNewCodeBar->codeBarTag );
					} else {
						s->addOneCoupon( COUPON_INCONNU, lpNewCodeBar->codeCoupon, lpNewCodeBar->montantCoupon, lpQuantite, lpNewCodeBar->codeBarTag );
					}
					
				}
				return;
			}
		}

		/* le fabricant n'est pas encore enregistre
		 * montrer le dialog pour creer un nouveau fabricant:
		 * on peut ainsi donner un nom au fabricant (à la place du code)
		 * et un nom au coupon (à la place du code).
		 * Cette opération est facultative.
		 */
		MyBeep::beep();

		Console::Beep();
		MyNewFabricantDialog^ lpNewFabricantDialog = gcnew MyNewFabricantDialog();
		lpNewFabricantDialog->codeFabricant = lpNewCodeBar->codeFabricant;
		lpNewFabricantDialog->codeCoupon = lpNewCodeBar->codeCoupon;
		lpNewFabricantDialog->ShowDialog( this );

		if ( lpNewFabricantDialog->DialogResult == System::Windows::Forms::DialogResult::OK ) {
			MyFabricant^ lpNewFabricant = nullptr;
			if ( lpNewFabricantDialog->isFabricantSpecified ) {
				// nom de Fabricant entré
				lpNewFabricant = gcnew MyFabricant( lpNewFabricantDialog->nomFabricant, lpNewCodeBar->codeFabricant );
				if ( lpNewFabricantDialog->isCouponSpecified )
					lpNewFabricant->addOneCoupon( lpNewFabricantDialog->nomCoupon, lpNewCodeBar->codeCoupon, lpNewCodeBar->montantCoupon, lpQuantite, lpNewCodeBar->codeBarTag );
				else
					lpNewFabricant->addOneCoupon( COUPON_INCONNU, lpNewCodeBar->codeCoupon, lpNewCodeBar->montantCoupon, lpQuantite, lpNewCodeBar->codeBarTag );
			} else {
				// nom de Fabricant inconnu
				lpNewFabricant = gcnew MyFabricant( FABRICANT_INCONNU, lpNewCodeBar->codeFabricant );
				lpNewFabricant->isUnknown = true;
				if ( lpNewFabricantDialog->isCouponSpecified )
					lpNewFabricant->addOneCoupon( lpNewFabricantDialog->nomCoupon, lpNewCodeBar->codeCoupon, lpNewCodeBar->montantCoupon, lpQuantite, lpNewCodeBar->codeBarTag );
				else
					lpNewFabricant->addOneCoupon( COUPON_INCONNU, lpNewCodeBar->codeCoupon, lpNewCodeBar->montantCoupon, lpQuantite, lpNewCodeBar->codeBarTag );
			}

			this->m_fabricantsList->Add( lpNewFabricant );
		}
	}

	//private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	//	// Check changes saved
	//	if ( this->changesDone->Equals(true) ) {
	//		if ( MessageBox::Show( "Voulez-vous sauvegarder vos changements avant de continuer ?",
	//			"Gestionnaire de coupons", MessageBoxButtons::YesNo,
	//			MessageBoxIcon::Warning ) == System::Windows::Forms::DialogResult::No ) return;
	//	}
	//	// Initialisation
	//	this->InitializeApplication();
	//}

	private: void saveChanges() {

		FileStream^ lpFileStream = nullptr;
		MyXmlWriter^ lpMyXmlWriter = nullptr;

		if (this->m_outputFileName != nullptr) {
			lpFileStream = gcnew FileStream(this->m_outputFileName, FileMode::Open);
			lpMyXmlWriter = gcnew MyXmlWriter();
			lpMyXmlWriter->SaveFabricantsList(this->m_fabricantsList, lpFileStream);
			lpFileStream->Close();
			this->m_changesDone = false;
		}
	}
	
	private: void checkChangesSaved() {

		if ( this->m_changesDone->Equals(true) ) {
			if ( MessageBox::Show( "Voulez-vous sauvegarder vos changements avant de continuer ?",
				"Gestionnaire de coupons", MessageBoxButtons::YesNo,
				MessageBoxIcon::Warning ) == System::Windows::Forms::DialogResult::Yes ) {
				this->saveChanges();
			}
			this->m_changesDone = false;
		}
	}

	/*
	 * Called when the form is loaded
	 */
	private: System::Void form_load(System::Object^  sender, System::EventArgs^  e) {

		this->InitializeApplication();

		switch (m_actionId) {
		case 0 :
			/*
			 * start from an empty file
			 */
			{
				// ask for a file name
				SelectEmptyFileDialog^ lpSelectEmptyFileDialog = gcnew SelectEmptyFileDialog();
				if ( lpSelectEmptyFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK ) {
					this->m_outputFileName = lpSelectEmptyFileDialog->getSelectedFileName();
					lpSelectEmptyFileDialog->Close();
					this->toolStripStatusLabel1->Text = "Fichier: " + this->m_outputFileName;
					this->loadXmlFile();
					this->toolStripStatusLabel2->Text = "Sauvegarde: " + this->m_lastSaveDate;
					// create the Tom&Co fabricant if not yet done
					MyTomCoFabricant^ lpTomFabricantTemp = gcnew MyTomCoFabricant ();
					if ( ! m_fabricantsList->Contains( lpTomFabricantTemp ) )
						m_fabricantsList->Add( lpTomFabricantTemp );
				}
				delete lpSelectEmptyFileDialog;
				//show the List
				this->showListView();
			}
			break;
		case 1 :
			/*
			 * start from an existing file
			 */
			{
				OpenFileDialog^ lpOpenFileDialog = gcnew OpenFileDialog;
				lpOpenFileDialog->Title = "Ouvrir un fichier de coupons";
				lpOpenFileDialog->Filter = "Fichier xml (*.xml)|*.xml";

				String^ lpXmlFileName;

				if (lpOpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
					if ( (lpXmlFileName = lpOpenFileDialog->FileName) != nullptr ) {
						this->m_outputFileName = lpXmlFileName;
						this->toolStripStatusLabel1->Text = "Fichier: " + this->m_outputFileName;
						this->loadXmlFile();
						this->toolStripStatusLabel2->Text = "Sauvegarde: " + this->m_lastSaveDate;
						// create the Tom&Co fabricant if not yet done
						MyTomCoFabricant^ lpTomFabricantTemp = gcnew MyTomCoFabricant ();
						if ( ! m_fabricantsList->Contains( lpTomFabricantTemp ) )
							m_fabricantsList->Add( lpTomFabricantTemp );
					}
				}
				delete lpOpenFileDialog;
				//show the List
				this->showListView();
			}
			break;
		default :
			this->Close();
		}

		//this->panel1->Hide();
	}

	private: void loadXmlFile() {

		MyXmlParser^ myXmlParser;

		try {
			myXmlParser = gcnew MyXmlParser( this->m_outputFileName );
			myXmlParser->ParseFabricant( this->m_fabricantsList );
			this->m_lastSaveDate = myXmlParser->getLastSaveDate();
			delete myXmlParser;
		} catch (XmlException^ lpEx) {
			MessageBox::Show( lpEx->Message,
						"Gestionnaire de coupons", MessageBoxButtons::OK,
						MessageBoxIcon::Error );
			//Diagnostics::Debug::WriteLine( "ERROR: " + e );
		}
	}

/* ------------------------------------
 * Events functions
 * ------------------------------------ */
	private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->saveChanges();
		this->saveToolStripButton->Enabled = false;
	}


	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->checkChangesSaved();
		this->Close();
	}

	private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		this->checkChangesSaved();
	}

	private: System::Void manualCouponStripButton_Click(System::Object^  sender, System::EventArgs^  e) {
		MyManualCouponForm^ lpManualCouponForm = gcnew MyManualCouponForm();
		lpManualCouponForm->TopLevel = false;
		this->panel1->Controls->Clear();
		this->panel1->Controls->Add( lpManualCouponForm );
		lpManualCouponForm->Show();
	}

	private: System::Void autoCouponStripButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->panel1->Show();
	}
};
}
