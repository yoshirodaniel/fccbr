// Hello World program 
// ANSI Codes
// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

#include <iostream>

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif


class matriz2D 
{
	public:
		int **ptr_matrix;
		int n_rows;
		int m_columns;

	matriz2D()
	{
		ptr_matrix=nullptr;
		n_rows=0;
		m_columns=0;
	}

	void crear_matriz()
	{
		std::cout<<"\t\t___Creando una matriz n*m ____\n";
		std::cout<<"Enter rows_number: ";
		std::cin>>n_rows;
		std::cout<<"Enter columns_number: ";
		std::cin>>m_columns;
		
		ptr_matrix=new int*[n_rows];
		for (int i{0};i<n_rows;i++)
		{
			ptr_matrix[i]=new int[m_columns];
		}

	}


	void definir_matriz()
	{
		char simbolo{'+'};
		std::cout<<"Enter a symbol(#,*,$): ";
		std::cin>>simbolo;
		for (int i{0};i<n_rows;i++)
		{
			for(int e{0};e<m_columns;e++)
			{
				ptr_matrix[i][e]=simbolo;
			}
		}
	}

	void imprimir_matriz()
	{
		std::cout<<std::endl;
		for (int i=0;i<n_rows;i++)
		{
			for(int e=0;e<m_columns;e++)
			{
				std::cout<<static_cast<char>(ptr_matrix[i][e]);
				if (e==m_columns-1)
				{
					std::cout<<'\n';
				} 
			}
		}
	}

	void modificar_matriz() //Pide al usuario la posicion(fila y columna) que desea modificar
	{
		int position_row;
		int position_column;
		char simbolo{'$'};
		std::cout<<"\n\n\t\t__Modificando una posicion especifica de la matriz creada__\n";
	
		std::cout<<"Enter the row: ";
		std::cin>>position_row;
		std::cout<<"Enter the column: ";
		std::cin>>position_column;
		std::cout<<"Enter a symbol: ";
		std::cin>>simbolo;

		position_row=position_row-1;
		position_column=position_column-1;
		for (int i{0};i<n_rows;i++)
		{
			for(int e{0};e<m_columns;e++)
			{
				if (i==position_row & e==position_column)
				{
					ptr_matrix[i][e]=simbolo;
				}
				else
				{
					continue;
					//std::cout<<"No puede ocurrir!!";
				}
			}
		}
	}

	void Borrar_memoria() //<-------------------------------BORRAR MEMORIA--------
	{
		for(int i{0};i<n_rows;i++)
		{
			delete[]ptr_matrix[i];

		}
		delete[]ptr_matrix;
		ptr_matrix=nullptr;
	}

	void Show_Caratula_cs()
	{
		std::system(CLEAR_COMMAND);            // Comando para borrar todo el contenido de la pantalla
		std::cout << "\x1B[H";          // Codigo para colocar el cursor en el canto superior izquierdo

		std::cout << "\x1B[m";             // Resetear color a valor por defecto
		std::cout << "\x1B[31;1m Universidad Catolica San Pablo \x1B[m" << std::endl; 
		std::cout << "\x1B[33;1m Computer Science \x1B[m" << std::endl; 
		std::cout << "\x1B[37;1m Curso de C++ Basico / Intermedio \x1B[m" << std::endl; 
		std::cout << "\x1B[38;5;46m Yoshiro Daniel Quispe Jihuallanca \x1B[m" << std::endl; 
		std::cout << "\x1B[3;38;5;160m Arequipa 2025 - Summer \x1B[m" << std::endl; 
	}


	

};

int main() 
{   
	matriz2D my_matrix;

	my_matrix.Show_Caratula_cs();
	my_matrix.crear_matriz();
	my_matrix.definir_matriz();
	my_matrix.imprimir_matriz();

	my_matrix.modificar_matriz();
	my_matrix.imprimir_matriz();
	my_matrix.Borrar_memoria(); //Borra la memoria asignada a la matriz
	//my_matrix.imprimir_matriz(); //Esta linea no deberia imprimir nada <------------ Comprobar

	return 0;
}
























