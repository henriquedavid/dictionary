#include <iostream>
#include <string>

#include "../include/DAL.h"


int main(){

	//================================================================
	//=================== TESTE DA VERSÃO DAL ========================
	//================================================================

	{

		dic::DAL dic_;

		// ============== Teste de Inserção ============== 

		bool insercao_1 = dic_.insert(1, "Henrique");
		bool insercao_2 = dic_.insert(2, "Pablo");
		bool insercao_3 = dic_.insert(100, "Selan");
		bool insercao_4 = dic_.insert(50, "Igor");

		if(insercao_1)
			std::cout << "Inserido!\n";
		else
			std::cout << "Não inserido!\n";

		if(insercao_2)
			std::cout << "Inserido!\n";
		else
			std::cout << "Não inserido!\n";

		if(insercao_3)
			std::cout << "Inserido!\n";
		else
			std::cout << "Não inserido!\n";

		if(insercao_4)
			std::cout << "Inserido!\n";
		else
			std::cout << "Não inserido!\n";

		// ============== Teste de Busca ============== 

		std::string dado;
		bool busca_1 = dic_.search(100, dado);

		if(busca_1)
			std::cout << "Dado = " << dado << std::endl;
		else
			std::cout << "Não encontrado!\n";

		// ============== Teste do Remove ==============

		std::string nome_i = "Igor";
		bool remove_1 = dic_.remove(50, nome_i);

		if(remove_1)
			std::cout << "Removeu o dado!" << std::endl;
		else
			std::cout << "Não foi removido!\n";


		// ============== Teste do Min ============== 

		int min_key = dic_.min();

		std::cout << "A menor chave é " << min_key << std::endl;

		// ============== Teste do Max ============== 

		int max_key = dic_.max();

		std::cout << "A maior chave é " << max_key << std::endl;


		// ============== Teste do Predecessor ============== 

		int key_1;
		bool pred = dic_.predecessor(2, key_1);

		if(pred)
			std::cout << "A chave predecessora é " << key_1 << std::endl;
		else
			std::cout << "Não foi possivel encontrar a prodecessora!\n";

		// ============== Teste do Sucessor ============== 

		int key_2;
		bool suc = dic_.sucessor(2, key_2);

		if(suc)
			std::cout << "A chave sucessora é " << key_2 << std::endl;
		else
			std::cout << "Não foi possivel encontrar a sucessora!\n";

		// ============== Teste de Impressão do Dicionário ============== 

		std::cout << dic_ << std::endl;

	}

	return 0;
}