#pragma once
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include <stdlib.h>

namespace CppCLRWinFormsProject {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			//
		}
		void shuffler(double** matrix, int rows, int cols)
		{
			srand(time(0));

			for (int i = rows - 1; i > 0; --i) {
				int j = rand() % (i + 1);
				if (i != j) {
					double* temp = matrix[i];
					matrix[i] = matrix[j];
					matrix[j] = temp;
				}
			}

		}

		string getfilename(System::String^ file) {
			string stdfilename;
			for (int i = 0; i < filename->Length; i++) {
				stdfilename.push_back(static_cast<char>(file[i]));
			}
			return stdfilename;
		}

		void deallocateMatrices() {
			if (data != nullptr) {
				for (int i = 0; i < r; i++) {
					delete[] data[i];
				}
				delete[] data;
				data = nullptr;
			}

			if (pearson != nullptr) {
				for (int i = 0; i < r; i++) {
					delete[] pearson[i];
				}
				delete[] pearson;
				pearson = nullptr;
			}

			if (binary != nullptr) {
				for (int i = 0; i < r; i++) {
					delete[] binary[i];
				}
				delete[] binary;
				binary = nullptr;
			}
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
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ previewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ bitmapToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ displayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ signatureToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ findToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ signatureToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ findToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: String^ filename;
	private: double** pearson;
	private: double** data;
	private: int** binary;

	private: System::Windows::Forms::ToolStripMenuItem^ pearsonCorrelationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ discretizedMatrixToolStripMenuItem;
	private: String^ preview;
	private: int r, c;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ zoomToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ correlationMatrixToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ zoomOutToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ closeToolStripMenuItem;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;

	private: System::Windows::Forms::PictureBox^ pictureBox2;

	protected:

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->previewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pearsonCorrelationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->discretizedMatrixToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bitmapToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->displayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->correlationMatrixToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->signatureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->findToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->signatureToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->findToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoomOutToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->fileToolStripMenuItem,
					this->bitmapToolStripMenuItem, this->signatureToolStripMenuItem, this->signatureToolStripMenuItem1, this->zoomToolStripMenuItem,
					this->zoomOutToolStripMenuItem1, this->closeToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(411, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->openToolStripMenuItem,
					this->previewToolStripMenuItem, this->pearsonCorrelationToolStripMenuItem, this->discretizedMatrixToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			// 
			// previewToolStripMenuItem
			// 
			this->previewToolStripMenuItem->Name = L"previewToolStripMenuItem";
			this->previewToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->previewToolStripMenuItem->Text = L"Preview";
			this->previewToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::previewToolStripMenuItem_Click);
			// 
			// pearsonCorrelationToolStripMenuItem
			// 
			this->pearsonCorrelationToolStripMenuItem->Name = L"pearsonCorrelationToolStripMenuItem";
			this->pearsonCorrelationToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->pearsonCorrelationToolStripMenuItem->Text = L"Pearson Correlation";
			this->pearsonCorrelationToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::pearsonCorrelationToolStripMenuItem_Click);
			// 
			// discretizedMatrixToolStripMenuItem
			// 
			this->discretizedMatrixToolStripMenuItem->Name = L"discretizedMatrixToolStripMenuItem";
			this->discretizedMatrixToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->discretizedMatrixToolStripMenuItem->Text = L"Discretized Matrix";
			this->discretizedMatrixToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::discretizedMatrixToolStripMenuItem_Click);
			// 
			// bitmapToolStripMenuItem
			// 
			this->bitmapToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->displayToolStripMenuItem,
					this->correlationMatrixToolStripMenuItem
			});
			this->bitmapToolStripMenuItem->Name = L"bitmapToolStripMenuItem";
			this->bitmapToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->bitmapToolStripMenuItem->Text = L"Bitmap";
			// 
			// displayToolStripMenuItem
			// 
			this->displayToolStripMenuItem->Name = L"displayToolStripMenuItem";
			this->displayToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->displayToolStripMenuItem->Text = L"Binary";
			this->displayToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::binaryToolStripMenuItem_Click);
			// 
			// correlationMatrixToolStripMenuItem
			// 
			this->correlationMatrixToolStripMenuItem->Name = L"correlationMatrixToolStripMenuItem";
			this->correlationMatrixToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->correlationMatrixToolStripMenuItem->Text = L"Correlation Matrix";
			this->correlationMatrixToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::correlationMatrixToolStripMenuItem_Click);
			// 
			// signatureToolStripMenuItem
			// 
			this->signatureToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->findToolStripMenuItem1 });
			this->signatureToolStripMenuItem->Name = L"signatureToolStripMenuItem";
			this->signatureToolStripMenuItem->Size = System::Drawing::Size(74, 20);
			this->signatureToolStripMenuItem->Text = L"Permutate";
			// 
			// findToolStripMenuItem1
			// 
			this->findToolStripMenuItem1->Name = L"findToolStripMenuItem1";
			this->findToolStripMenuItem1->Size = System::Drawing::Size(102, 22);
			this->findToolStripMenuItem1->Text = L"Find\?";
			this->findToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::findToolStripMenuItem1_Click);
			// 
			// signatureToolStripMenuItem1
			// 
			this->signatureToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->findToolStripMenuItem });
			this->signatureToolStripMenuItem1->Name = L"signatureToolStripMenuItem1";
			this->signatureToolStripMenuItem1->Size = System::Drawing::Size(69, 20);
			this->signatureToolStripMenuItem1->Text = L"Signature";
			// 
			// findToolStripMenuItem
			// 
			this->findToolStripMenuItem->Name = L"findToolStripMenuItem";
			this->findToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->findToolStripMenuItem->Text = L"Find\?";
			this->findToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::findToolStripMenuItem_Click);
			// 
			// zoomToolStripMenuItem
			// 
			this->zoomToolStripMenuItem->Name = L"zoomToolStripMenuItem";
			this->zoomToolStripMenuItem->Size = System::Drawing::Size(27, 20);
			this->zoomToolStripMenuItem->Text = L"+";
			this->zoomToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::zoomInToolStripMenuItem_Click);
			// 
			// zoomOutToolStripMenuItem1
			// 
			this->zoomOutToolStripMenuItem1->Name = L"zoomOutToolStripMenuItem1";
			this->zoomOutToolStripMenuItem1->Size = System::Drawing::Size(24, 20);
			this->zoomOutToolStripMenuItem1->Text = L"-";
			this->zoomOutToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::zoomOutToolStripMenuItem1_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->closeToolStripMenuItem->Text = L"Exit";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::closeToolStripMenuItem_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(72, 120);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(250, 250);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(72, 120);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(250, 250);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Form1::pictureBox2_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 56);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(389, 392);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->Visible = false;
			this->richTextBox1->WordWrap = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(411, 454);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Data Clustering and Visualising App";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog1->ShowDialog();
		filename = openFileDialog1->FileName;
		string stdfile = getfilename(filename);

		if (filename != nullptr && filename != "") {
			ifstream file(stdfile);
			if (!file.is_open()) {
				MessageBox::Show("Error opening file!");
				return;
			}
			int row, col;
			file >> row >> col;
			r = row;
			c = col;
			data = new double* [row];
			pearson = new double* [row];
			binary = new int* [row];
			for (int i = 0; i < row; i++) {
				data[i] = new double[col];
				pearson[i] = new double[row];
				binary[i] = new int[row];
			}

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					file >> data[i][j];
				}
			}

			// Prepare the preview string in matrix format
			preview = "";
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					preview += Convert::ToString(data[i][j]) + "\t"; // Separate columns by tabs
				}
				preview += "\n"; // Move to the next row
			}
			file.close();
		}

	}

private: System::Void previewToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	richTextBox1->Visible = true;

	// Hide PictureBox 1 and PictureBox 2
	pictureBox1->Visible = false;
	pictureBox2->Visible = false;

	// Display the preview in RichTextBox
	richTextBox1->Text = preview;
}

private: System::Void pearsonCorrelationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	richTextBox1->Visible = true;

	// Hide PictureBox 1 and PictureBox 2
	pictureBox1->Visible = false;
	pictureBox2->Visible = false;

	for (int i = 0; i < r; i++) {
 		for (int j = 0; j < r; j++) {
			double sumx = 0, sumy = 0, sumxy = 0, sumxsquare = 0, sumysquare = 0;
			for (int k = 0; k < c; k++) {
				sumx += data[i][k];
				sumy += data[j][k];
				sumxy += data[i][k] * data[j][k];
				sumxsquare += data[i][k] * data[i][k];
				sumysquare += data[j][k] * data[j][k];
			}
			double numerator = (c * sumxy) - (sumx * sumy);
			double denumerator = sqrt(((c * sumxsquare) - (sumx * sumx)) * ((c * sumysquare) - (sumy * sumy)));

			if (denumerator == 0) {
				pearson[i][j] = 0;
			}
			else {
				pearson[i][j] = numerator / denumerator;
			}
		}
	}

	richTextBox1->Clear();
	preview = "";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			preview += Convert::ToString(pearson[i][j]) + "\t"; // Separate columns by tabs
		}
		preview += "\n"; // Move to the next row
	}
	richTextBox1->Text = preview;
}
private: System::Void discretizedMatrixToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	richTextBox1->Visible = true;

	// Hide PictureBox 1 and PictureBox 2
	pictureBox1->Visible = false;
	pictureBox2->Visible = false;

	for (int i = 0; i < r; i++) {
		double colmean = 0;
		for (int j = 0; j < r; j++) {
			colmean += pearson[j][i];
		}
		colmean /= r;
		for (int j = 0; j < r; j++) {
			binary[j][i] = (pearson[j][i] > colmean) ? 0 : 1;
		}
	}

	richTextBox1->Clear();
	preview = "";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			preview += Convert::ToString(binary[i][j]) + "\t"; // Separate columns by tabs
		}
		preview += "\n"; // Move to the next row
	}
	richTextBox1->Text = preview;

}
private: System::Void binaryToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Hide the RichTextBox
	richTextBox1->Visible = false;

	// Show PictureBox 1 and PictureBox 2
	pictureBox1->Visible = true;
	pictureBox2->Visible = false;

	
	Bitmap^ bmp = gcnew Bitmap(r, r);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {

			if (binary[i][j] == 1) {
				bmp->SetPixel(i, j, Color::Black);
				pictureBox1->Image = bmp;
			}
			else {
				bmp->SetPixel(i, j, Color::Beige);
				pictureBox1->Image = bmp;
			}

		}
	}
}
private: System::Void correlationMatrixToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Hide the RichTextBox
	richTextBox1->Visible = false;

	// Show PictureBox 1 and PictureBox 2
	pictureBox1->Visible = false;
	pictureBox2->Visible = true;

	Bitmap^ bmp1 = gcnew Bitmap(r, r);
	for (int i = 0; i < r; i++) {
		double max = -100;
		for (int j = 0; j < r; j++)
		{
			if (pearson[j][i] > max)
			{
				max = pearson[j][i];
			}
		}
		for (int j = 0; j < r; j++) {
			if (pearson[j][i] >= 0) {
				int pixel = (int)(pearson[j][i] / max * 255);
				bmp1->SetPixel(i, j, Color::FromArgb(0, pixel, 0));
			}
			else {
				int pixel = (int)(pearson[j][i] / max * 255 * -1);
				bmp1->SetPixel(i, j, Color::FromArgb(0, pixel, 0));
			}
		}
		pictureBox2->Image = bmp1;
	}
}
private: System::Void zoomInToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pictureBox1->Visible == true) {
		pictureBox1->Height *= 2;
		pictureBox1->Width *= 2;
	}
	else if(pictureBox2->Visible == true)
	{
	pictureBox2->Height *= 2;
	pictureBox2->Width *= 2;
	}
}
private: System::Void zoomOutToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (pictureBox1->Visible == true) {
		pictureBox1->Height *= 0.5;
		pictureBox1->Width *= 0.5;
	}
	else if (pictureBox2->Visible == true) {
		pictureBox2->Height *= 0.5;
		pictureBox2->Width *= 0.5;
	}
}
private: System::Void findToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Hide the RichTextBox
	richTextBox1->Visible = true;

	// Show PictureBox 1 and PictureBox 2
	pictureBox1->Visible = false;
	pictureBox2->Visible = false;

	shuffler(data, r, c);

	richTextBox1->Clear();
	preview = "";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			preview += Convert::ToString(data[i][j]) + "\t"; // Separate columns by tabs
		}
		preview += "\n"; // Move to the next row
	}
	richTextBox1->Text = preview;

}


private: System::Void findToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Hide the RichTextBox
	richTextBox1->Visible = true;

	// Show PictureBox 1 and PictureBox 2
	pictureBox1->Visible = false;
	pictureBox2->Visible = false;
		double* signature = new double[r];
		for (int i = 0; i < r; i++) {
			double rowsum = 0;
			double rowmean = 0;
			for (int j = 0; j < c; j++) {
				rowsum += data[i][j];
			}
			rowmean = rowsum / r; // Calculate mean by dividing by the number of elements in the row, not the number of rows
			signature[i] = rowmean * rowsum; // Multiply the row sum by its mean value
		}


			// Sorting the signature matrix using bubble sort
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < r - 1; j++) {
				if (signature[j] > signature[j + 1]) {
					// Swap values in signature array
					double temp = signature[j];
					signature[j] = signature[j + 1];
					signature[j + 1] = temp;

					// Swap corresponding rows in pearson matrix
					for (int k = 0; k < c; k++) {
						double temp_data = data[j][k];
						data[j][k] = data[j + 1][k];
						data[j + 1][k] = temp_data;
					}
				}
			} 
		}

		richTextBox1->Clear();
		preview = "";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				preview += Convert::ToString(data[i][j]) + "\t"; // Separate columns by tabs
			}
			preview += "\n"; // Move to the next row
		}
		richTextBox1->Text = preview;

}
private: System::Void closeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	deallocateMatrices();

	// Close the window form
	this->Close();  
}


private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
	}
