#include "recorrencia.hpp"

// Função para ler do arquivo tokenizando
void Token::readFile()
{
    ifstream myFile;
    string caminho, linha, words;
    int valor;

    caminho = "arquivos/filosofia.txt";

    myFile.open(caminho);

    if (myFile.fail())
    {
        cout << "Problemas na abertura do arquivo!" << endl;
    }

    while (!myFile.eof())
    {
        while (getline(myFile, linha, '\n'))
        {
            linha.append(" ");
            std::stringstream X(linha);
            while (getline(X, words, ' '))
            {
                while (words.back() == ',' || words.back() == '.' || words.back() == '!' || words.back() == '?' || words.back() == ';' || words.back() == ':' || words.back() == ')' || words.back() == '-' || words.back() == '\'' || words.back() == '\"' || words.back() == '/')
                    words.pop_back();
                while (words.front() == '(' || words.front() == '-' || words.front() == '\'' || words.front() == '\"')
                    words.erase(words.begin());
                valor = words[1];
                if (words.front() == -61 && valor >= -128 && valor <= -99)
                    words[1] = words[1] + 32;
                transform(words.begin(), words.end(), words.begin(), [](unsigned char c)
                          { return tolower(c); });
                if (words.size() > 0)
                    Arquivo.push_back(words);
            }
        }
    }

    myFile.close();
}

/// Preenche map com as stop words do arquivo
void Token::preencheStpW()
{
    ifstream myFile;
    string caminho, words;

    caminho = "arquivos/stopwords.txt";

    myFile.open(caminho);

    if (!myFile)
        printf("Arquivo stopwords não encontrado\n");

    else
    {
        while (getline(myFile, words, '\n'))
        {
            if (words.back() == ' ')
                words.pop_back();
            StpWrds.insert({words, 1});
        }
    }
    myFile.close();
}

/// remove stop words e insere em um map
void Token::removeStpW(vector<string>&arq)
{
    map<string, int>::iterator t;
    map<string, int>::iterator t2;

    for (auto i : Arquivo)
    {
        t = StpWrds.find(i);

        if (t == StpWrds.end())
        {
            t2 = ArquivoSemStp.find(i);
            if (t2 == ArquivoSemStp.end())
            {
                ArquivoSemStp.insert({i, 1});
                arq.push_back(i);
            }
            else
            {
                t2->second++;            
            }
        }
    }
}

////calcula normalize e insere no map final, que tem a palavra e o valor normalizado
void Token::mapWords(map<string,float>&Hash)
{
    float normalize;
     
    float deno=maxMin();

    for (auto i : ArquivoSemStp)
    {
        normalize = i.second / deno;
        Hash.insert({i.first, normalize});
    }
}

/// função que imprime o map com o normalize e com a palavra
void Token::imprimirMap()
{
    map<string, float>::iterator itr;

    for (itr = Hash.begin(); itr != Hash.end(); ++itr)
    {
        cout << itr->first << " ....";
        cout << "Normalize " << itr->second << endl;
    }
}

/// alcula o maximo e minimo do RP
float Token::maxMin()
{
    /// funcao = RP / (max(RP) - min(RP))

    map<string, int>::iterator itr;

    itr=ArquivoSemStp.begin();

    float max = itr->second;
    float min = itr->second;

    for (itr = ArquivoSemStp.begin(); itr != ArquivoSemStp.end(); ++itr)
    {
        if (max < itr->second)
            max = itr->second;

        if (min > itr->second)
            min = itr->second;
    }

    float denominadorNormalize=(max-min);

    return denominadorNormalize;
}