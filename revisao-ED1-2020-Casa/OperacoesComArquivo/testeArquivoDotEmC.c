#include <stdio.h>
#include <string.h>

void main()
{
 FILE *arquivoDot;
 arquivoDot = fopen("ArquivoTesteParaLinguagemDot.dot","w");
 //escrevendo no arquivo
 fputs("digraph",arquivoDot);
 fputc('{',arquivoDot);
 fputc('\n',arquivoDot);
 fputs("1 -> 2;\n",arquivoDot);
 fputs("2 -> 3;\n",arquivoDot);
 fputs("3 -> 4;\n",arquivoDot);
 fputs("3 -> 5;\n",arquivoDot);
 fputs("3 -> 6;\n",arquivoDot);
 fputs("6 -> 7;\n",arquivoDot);
 fputs("6 -> 8;\n",arquivoDot);
 fputc('}',arquivoDot);
 fputc('\n',arquivoDot);
 fclose(arquivoDot);
 //comando abaixo e para processar o arquivo.dot e renderizar em png
 //                nomearquivo    nomePNG
 system("dot -Tpng ArquivoTesteParaLinguagemDot.dot -o grafoTeste.png");
}
