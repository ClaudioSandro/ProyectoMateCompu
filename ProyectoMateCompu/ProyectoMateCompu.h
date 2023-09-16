#pragma once
#include "FordFulkerson.h"


namespace ProyectoMateCompu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ProyectoMateCompu
	/// </summary>
	public ref class ProyectoMateCompu : public System::Windows::Forms::Form
	{
	private:
		FordFulkerson* fordFulkerson;



	public:
		ProyectoMateCompu(void)
		{
			InitializeComponent();


			fordFulkerson = new FordFulkerson(5);
		}


	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~ProyectoMateCompu()
		{
			if (components)
			{
				delete components;
			}

			// Libera la memoria de FordFulkerson
			delete fordFulkerson;
		}

	private: System::Windows::Forms::Label^ texto_ingresar_tamanio;
	private: System::Windows::Forms::Label^ texto_llenar_automatico;
	private: System::Windows::Forms::Label^ label_mostrar_matrix;
	private: System::Windows::Forms::Label^ texto_mostrar_flujo;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ text_resultado;
	private: System::Windows::Forms::Button^ button1;
	protected:

	protected:




	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->texto_ingresar_tamanio = (gcnew System::Windows::Forms::Label());
			this->texto_llenar_automatico = (gcnew System::Windows::Forms::Label());
			this->label_mostrar_matrix = (gcnew System::Windows::Forms::Label());
			this->texto_mostrar_flujo = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->text_resultado = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// texto_ingresar_tamanio
			// 
			this->texto_ingresar_tamanio->AutoSize = true;
			this->texto_ingresar_tamanio->Location = System::Drawing::Point(43, 34);
			this->texto_ingresar_tamanio->Name = L"texto_ingresar_tamanio";
			this->texto_ingresar_tamanio->Size = System::Drawing::Size(268, 16);
			this->texto_ingresar_tamanio->TabIndex = 0;
			this->texto_ingresar_tamanio->Text = L"Ingresar tamanio de la matrix (min:5, max:15)";
			// 
			// texto_llenar_automatico
			// 
			this->texto_llenar_automatico->AutoSize = true;
			this->texto_llenar_automatico->Location = System::Drawing::Point(46, 81);
			this->texto_llenar_automatico->Name = L"texto_llenar_automatico";
			this->texto_llenar_automatico->Size = System::Drawing::Size(178, 16);
			this->texto_llenar_automatico->TabIndex = 1;
			this->texto_llenar_automatico->Text = L"llenar automatica\? (0:si, 1:no)";
			// 
			// label_mostrar_matrix
			// 
			this->label_mostrar_matrix->AutoSize = true;
			this->label_mostrar_matrix->Location = System::Drawing::Point(63, 199);
			this->label_mostrar_matrix->Name = L"label_mostrar_matrix";
			this->label_mostrar_matrix->Size = System::Drawing::Size(134, 16);
			this->label_mostrar_matrix->TabIndex = 2;
			this->label_mostrar_matrix->Text = L"tu matrix cargara aqui";
			// 
			// texto_mostrar_flujo
			// 
			this->texto_mostrar_flujo->AutoSize = true;
			this->texto_mostrar_flujo->Location = System::Drawing::Point(34, 458);
			this->texto_mostrar_flujo->Name = L"texto_mostrar_flujo";
			this->texto_mostrar_flujo->Size = System::Drawing::Size(179, 16);
			this->texto_mostrar_flujo->TabIndex = 3;
			this->texto_mostrar_flujo->Text = L"El flujo maximo calculado es:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(412, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(407, 80);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 5;
			// 
			// text_resultado
			// 
			this->text_resultado->AutoSize = true;
			this->text_resultado->Location = System::Drawing::Point(382, 462);
			this->text_resultado->Name = L"text_resultado";
			this->text_resultado->Size = System::Drawing::Size(11, 16);
			this->text_resultado->TabIndex = 6;
			this->text_resultado->Text = L"-";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(405, 145);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"calcular";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// ProyectoMateCompu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(761, 514);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->text_resultado);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->texto_mostrar_flujo);
			this->Controls->Add(this->label_mostrar_matrix);
			this->Controls->Add(this->texto_llenar_automatico);
			this->Controls->Add(this->texto_ingresar_tamanio);
			this->Name = L"ProyectoMateCompu";
			this->Text = L"ProyectoMateCompu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}