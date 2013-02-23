#pragma once

#include "Form1.h"
#include "MyManualCouponForm.h"
#include "MyTomCoFabricant.h"
#include "SelectEmptyFileDialog.h"
#include "MyXmlParser.h"

namespace FirstWinNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_actionId = -1;
			m_lpAutoCouponForm = nullptr;
			m_lpManualCouponForm = nullptr;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  saveToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  autoCouponStripButton;
	private: System::Windows::Forms::ToolStripButton^  manualCouponStripButton;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel2;
	private: System::Windows::Forms::Panel^  panel1;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int m_actionId;
		List<MyFabricant^>^ m_lpMasterFabricantsList;
		String^ m_outputFileName;
		String^ m_lastSaveDate;
		CultureInfo^ m_lpcurrentCulture;
		Boolean^ m_changesDone;
		Form1^ m_lpAutoCouponForm;
		MyManualCouponForm^ m_lpManualCouponForm;

	/*
	 * InitializeApplication
	 */
	private: void InitializeApplication(void) {

		if (this->m_lpMasterFabricantsList != nullptr) {
			this->m_lpMasterFabricantsList->Clear();
			delete this->m_lpMasterFabricantsList;
		}
		this->m_lpMasterFabricantsList = gcnew List<MyFabricant^>(50);
		this->m_changesDone = false;
		this->m_outputFileName = nullptr;
		this->toolStripStatusLabel1->Text = "";
		this->toolStripStatusLabel2->Text = "";
		//this->saveToolStripButton->Enabled = false;
		// use french number display
		m_lpcurrentCulture = gcnew CultureInfo("fr-FR");
	}


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->saveToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->autoCouponStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->manualCouponStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->toolStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->saveToolStripButton, 
				this->autoCouponStripButton, this->manualCouponStripButton});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(594, 25);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// saveToolStripButton
			// 
			this->saveToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->saveToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"saveToolStripButton.Image")));
			this->saveToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->saveToolStripButton->Name = L"saveToolStripButton";
			this->saveToolStripButton->Size = System::Drawing::Size(23, 22);
			this->saveToolStripButton->Text = L"toolStripButton1";
			this->saveToolStripButton->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripButton_Click);
			// 
			// autoCouponStripButton
			// 
			this->autoCouponStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->autoCouponStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"autoCouponStripButton.Image")));
			this->autoCouponStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->autoCouponStripButton->Name = L"autoCouponStripButton";
			this->autoCouponStripButton->Size = System::Drawing::Size(139, 22);
			this->autoCouponStripButton->Text = L"Coupon avec CodeBarre";
			this->autoCouponStripButton->Click += gcnew System::EventHandler(this, &MyForm::autoCouponStripButton_Click);
			// 
			// manualCouponStripButton
			// 
			this->manualCouponStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->manualCouponStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"manualCouponStripButton.Image")));
			this->manualCouponStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->manualCouponStripButton->Name = L"manualCouponStripButton";
			this->manualCouponStripButton->Size = System::Drawing::Size(138, 22);
			this->manualCouponStripButton->Text = L"Coupon sans CodeBarre";
			this->manualCouponStripButton->Click += gcnew System::EventHandler(this, &MyForm::manualCouponStripButton_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripStatusLabel1, 
				this->toolStripStatusLabel2});
			this->statusStrip1->Location = System::Drawing::Point(0, 460);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(594, 22);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripStatusLabel1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(118, 17);
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
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
			// panel1
			// 
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 25);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(594, 435);
			this->panel1->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(594, 482);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->toolStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Gestionnaire de coupons";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:
		property int actionId {
			void set( int value ) {
				m_actionId = value;
			}
		}

	private: void loadXmlFile() {
		MyXmlParser^ myXmlParser;

		try {
			myXmlParser = gcnew MyXmlParser( this->m_outputFileName );
			myXmlParser->ParseFabricant( this->m_lpMasterFabricantsList );
			this->m_lastSaveDate = myXmlParser->getLastSaveDate();
			delete myXmlParser;
		} catch (XmlException^ lpEx) {
			MessageBox::Show( lpEx->Message,
						"Gestionnaire de coupons", MessageBoxButtons::OK,
						MessageBoxIcon::Error );
			//Diagnostics::Debug::WriteLine( "ERROR: " + e );
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

	private: void saveChanges() {

		FileStream^ lpFileStream = nullptr;
		MyXmlWriter^ lpMyXmlWriter = nullptr;

		if (this->m_outputFileName != nullptr) {
			lpFileStream = gcnew FileStream(this->m_outputFileName, FileMode::Open);
			lpMyXmlWriter = gcnew MyXmlWriter();
			lpMyXmlWriter->SaveFabricantsList(this->m_lpMasterFabricantsList, lpFileStream);
			lpFileStream->Close();
			this->m_changesDone = false;
		}
	}
	
	private: void loadAutoCouponForm() {
		if ( this->m_lpManualCouponForm != nullptr )
			delete m_lpManualCouponForm;
		if ( this->m_lpAutoCouponForm != nullptr )
			delete m_lpAutoCouponForm;
		this->m_lpAutoCouponForm = gcnew Form1( this->m_lpMasterFabricantsList, this->m_lpcurrentCulture );
		this->panel1->Controls->Clear();
		this->panel1->Controls->Add( m_lpAutoCouponForm );
		this->autoCouponStripButton->Enabled = false;
		this->manualCouponStripButton->Enabled = true;
		m_lpAutoCouponForm->Show();
	}

	private: void loadManualCouponForm() {
		this->checkChangesSaved();
		if ( this->m_lpManualCouponForm != nullptr )
			delete m_lpManualCouponForm;
		if ( this->m_lpAutoCouponForm != nullptr )
			delete m_lpAutoCouponForm;
		m_lpManualCouponForm = gcnew MyManualCouponForm( );
		this->panel1->Controls->Clear();
		this->panel1->Controls->Add( m_lpManualCouponForm );
		this->autoCouponStripButton->Enabled = true;
		this->manualCouponStripButton->Enabled = false;
		m_lpManualCouponForm->Show();
	}

/* ------------------------------------
 * Events functions
 * ------------------------------------ */
	private: System::Void autoCouponStripButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->loadAutoCouponForm();
	}
	
	private: System::Void manualCouponStripButton_Click(System::Object^  sender, System::EventArgs^  e) {
		 this->loadManualCouponForm();
	}

	/*
	 * Called when the form is loaded
	 */
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

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
					if ( ! m_lpMasterFabricantsList->Contains( lpTomFabricantTemp ) )
						m_lpMasterFabricantsList->Add( lpTomFabricantTemp );
				}
				delete lpSelectEmptyFileDialog;
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
						if ( ! m_lpMasterFabricantsList->Contains( lpTomFabricantTemp ) )
							m_lpMasterFabricantsList->Add( lpTomFabricantTemp );
					}
				}
				delete lpOpenFileDialog;
			}
			break;
		default :
			this->Close();
		}

		// load AutoCoupon form
		this->loadAutoCouponForm();
	}

	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		this->checkChangesSaved();
	}

	//private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//	this->checkChangesSaved();
	//	this->Close();
	//}

	private: System::Void saveToolStripButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->saveChanges();
		this->saveToolStripButton->Enabled = false;
	}
};
}
