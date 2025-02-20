# 💰 Sistema Bancário em C

**Descrição:** Este projeto é um **Sistema Bancário** desenvolvido em **C** para a disciplina de **Estruturas de Dados** no **segundo semestre da faculdade**. Ele utiliza **listas encadeadas** para armazenar contas e movimentações bancárias, permitindo realizar consultas, movimentações e persistir os dados em arquivos.

## 🚀 Funcionalidades  
✅ Gerenciamento de contas bancárias (cadastro, consulta e alteração)  
✅ Movimentação bancária (crédito, débito e transferências)  
✅ Organização de dados em **listas encadeadas**  
✅ Persistência de dados em **arquivos**  
✅ Ordenação e busca por **código** e **banco**  
✅ Interface no terminal com `gotoxy()` e telas organizadas  

## 🎓 O que foi aprendido
Durante o desenvolvimento deste projeto, foram aplicados os seguintes conceitos:

- **Listas encadeadas**: Armazenamento dinâmico de contas e movimentações
- **Manipulação de arquivos**: Funções para salvar e carregar dados (`gravarArquivo`, `lerArquivo`)
- **Ordenação e busca**: Implementação de **Bubble Sort** para ordenação (`ordenarPorBanco`, `ordenarPorCodigo`)
- **Consultas otimizadas**: Métodos para exibir informações organizadas (`consultarCod`, `consultarAlfa`, `consultar_mov`)
- **Tratamento de entrada de dados**: Validações robustas para evitar entradas inválidas (`validarNum`, `validarECompararComLista`)
- **Interface no terminal**: Uso de `gotoxy()` para melhorar a usabilidade no terminal
- **Alocação dinâmica de memória**: Uso de `malloc()` e `free()` para manipular estruturas de dados dinamicamente
- **Uso de ponteiros**: Manipulação eficiente de listas encadeadas e registros de movimentação
- **Modularização do código**: Separação do código em múltiplos arquivos (`Alteracao.c`, `Consultar.c`, etc.) para melhor organização
- **Gerenciamento de transações bancárias**: Lógica para créditos, débitos e transferências entre contas
- **Boas práticas de programação em C**: Organização do código, uso adequado de structs e headers (`Funcoes.h`)


## 📜 Licença  
Este projeto está licenciado sob a **MIT License** – veja o arquivo [LICENSE](LICENSE) para mais detalhes.
