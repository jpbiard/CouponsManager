#pragma once

namespace FirstWinNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyManualCouponForm
	/// </summary>
	public ref class MyManualCouponForm : public System::Windows::Forms::Form
	{
	public:
		MyManualCouponForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			// add some Columns to the ColumnModel
			this->columnModel1->Columns->Add(gcnew XPTable::Models::TextColumn("Text"));
			this->columnModel1->Columns->Add(gcnew XPTable::Models::CheckBoxColumn("CheckBox"));
			this->columnModel1->Columns->Add(gcnew XPTable::Models::ButtonColumn("Button"));
 
			// add some Rows and Cells to the TableModel
			this->tableModel1->Rows->Add(gcnew XPTable::Models::Row());
			this->tableModel1->Rows[0]->Cells->Add(gcnew XPTable::Models::Cell("Text 1"));
			this->tableModel1->Rows[0]->Cells->Add(gcnew XPTable::Models::Cell("CheckBox 1", true));
			this->tableModel1->Rows[0]->Cells->Add(gcnew XPTable::Models::Cell("Button 1"));
			this->tableModel1->Rows->Add(gcnew XPTable::Models::Row());
			this->tableModel1->Rows[1]->Cells->Add(gcnew XPTable::Models::Cell("Text 2"));
			this->tableModel1->Rows[1]->Cells->Add(gcnew XPTable::Models::Cell("CheckBox 2", false));
			this->tableModel1->Rows[1]->Cells->Add(gcnew XPTable::Models::Cell("Button 2"));
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyManualCouponForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: XPTable::Models::Table^  table1;
	private: XPTable::Models::ColumnModel^  columnModel1;
	private: XPTable::Models::TableModel^  tableModel1;
	private: System::Windows::Forms::Panel^  panel1;

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
			XPTable::Models::DataSourceColumnBinder^  dataSourceColumnBinder1 = (gcnew XPTable::Models::DataSourceColumnBinder());
			XPTable::Renderers::DragDropRenderer^  dragDropRenderer1 = (gcnew XPTable::Renderers::DragDropRenderer());
			this->table1 = (gcnew XPTable::Models::Table());
			this->columnModel1 = (gcnew XPTable::Models::ColumnModel());
			this->tableModel1 = (gcnew XPTable::Models::TableModel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->table1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// table1
			// 
			this->table1->BorderColor = System::Drawing::Color::Black;
			this->table1->ColumnModel = this->columnModel1;
			this->table1->DataMember = nullptr;
			this->table1->DataSourceColumnBinder = dataSourceColumnBinder1;
			dragDropRenderer1->ForeColor = System::Drawing::Color::Red;
			this->table1->DragDropRenderer = dragDropRenderer1;
			this->table1->GridLinesContrainedToData = false;
			this->table1->Location = System::Drawing::Point(21, 29);
			this->table1->Name = L"table1";
			this->table1->Size = System::Drawing::Size(667, 292);
			this->table1->TabIndex = 0;
			this->table1->TableModel = this->tableModel1;
			this->table1->Text = L"table1";
			this->table1->UnfocusedBorderColor = System::Drawing::Color::Black;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->table1);
			this->panel1->Location = System::Drawing::Point(12, 44);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(716, 362);
			this->panel1->TabIndex = 1;
			// 
			// MyManualCouponForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(740, 450);
			this->ControlBox = false;
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyManualCouponForm";
			this->ShowIcon = false;
			this->Text = L"MyManualCouponForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->table1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	public:	void setPanelToParent(Control^ lpParentControl) {
		this->panel1->Parent = lpParentControl;
	}

};

}
