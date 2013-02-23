#pragma once

#include "MyForm.h"

namespace FirstWinNet {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartDialog
	/// </summary>
	public ref class StartDialog : public System::Windows::Forms::Form
	{
	public:
		StartDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StartDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListView^  actionsListView;
	private: System::Windows::Forms::ImageList^  listViewmageList;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
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
			System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) {L"Commencer sans coupons pré-enregistrés"}, 
				1, System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0))), System::Drawing::Color::Empty, (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 
				9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)))));
			System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) {L"Continuer à partir d\'une précédente sauvegarde"}, 
				0, System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0))), System::Drawing::Color::Empty, (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 
				9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)))));
			System::Windows::Forms::ListViewItem^  listViewItem3 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(1) {L"Quitter l\'application"}, 
				2, System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0))), System::Drawing::Color::Empty, (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 
				9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)))));
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(StartDialog::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->actionsListView = (gcnew System::Windows::Forms::ListView());
			this->listViewmageList = (gcnew System::Windows::Forms::ImageList(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(64, 197);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(208, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Que voulez-vous faire \?";
			// 
			// actionsListView
			// 
			this->actionsListView->Activation = System::Windows::Forms::ItemActivation::OneClick;
			this->actionsListView->BackColor = System::Drawing::SystemColors::Control;
			this->actionsListView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->actionsListView->GridLines = true;
			listViewItem1->StateImageIndex = 0;
			listViewItem2->IndentCount = 1;
			listViewItem3->IndentCount = 2;
			this->actionsListView->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(3) {listViewItem1, listViewItem2, 
				listViewItem3});
			this->actionsListView->Location = System::Drawing::Point(42, 239);
			this->actionsListView->MultiSelect = false;
			this->actionsListView->Name = L"actionsListView";
			this->actionsListView->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->actionsListView->Size = System::Drawing::Size(476, 137);
			this->actionsListView->SmallImageList = this->listViewmageList;
			this->actionsListView->TabIndex = 1;
			this->actionsListView->UseCompatibleStateImageBehavior = false;
			this->actionsListView->View = System::Windows::Forms::View::List;
			this->actionsListView->Click += gcnew System::EventHandler(this, &StartDialog::listView_Click);
			// 
			// listViewmageList
			// 
			this->listViewmageList->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^  >(resources->GetObject(L"listViewmageList.ImageStream")));
			this->listViewmageList->TransparentColor = System::Drawing::Color::Transparent;
			this->listViewmageList->Images->SetKeyName(0, L"Icon_0334.ico");
			this->listViewmageList->Images->SetKeyName(1, L"Icon_0451.ico");
			this->listViewmageList->Images->SetKeyName(2, L"Icon_0027.ico");
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(147, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(281, 148);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// StartDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(574, 407);
			this->ControlBox = false;
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->actionsListView);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"StartDialog";
			this->Text = L"Démarrage";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void listView_Click(System::Object^  sender, System::EventArgs^  e) {
		int selectedActionIndex = -1;

		ListView::SelectedListViewItemCollection^ lpActions = this->actionsListView->SelectedItems;
		System::Collections::IEnumerator^ lpEnum = lpActions->GetEnumerator();
		while ( lpEnum->MoveNext() ) {
			ListViewItem^ lpItem = safe_cast<ListViewItem^>(lpEnum->Current);
			selectedActionIndex = lpItem->Index;
		}

		switch ( selectedActionIndex ) {
		case 0 :
		case 1 :
			{
				this->Hide();
				FirstWinNet::MyForm^ lpForm = gcnew FirstWinNet::MyForm();
				lpForm->actionId = selectedActionIndex;
				lpForm->ShowDialog( this );
				lpForm->Focus();

				lpForm->Close();
				this->Show();
			}
			break;
		default :
			this->Close();
			break;
		}
	}

	};
}
