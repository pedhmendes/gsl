# gsl
-- Gnu Scientific Library --

Códigos para ajudar a entender funções disponíveis na biblioteca. Mais informações [aqui](https://www.gnu.org/software/gsl/).

Codes that will help a better understanding of avaiable functions in the library. Mora information [here](https://www.gnu.org/software/gsl/).




<h3 id="intro">A Biblioteca</h3>
<ul><p>Uma ferramenta otima para programação científica em C é a gsl (GNU Scientific Library). Nessa página vou deixar programas simples onde implemento funções. Mais informações podem ser encontradas na página da <a href="https://www.gnu.org/software/gsl/">biblioteca</a>.</p></ul>

<ul><p>Caso não tenha a gsl instalada abra um terminal e siga os passos abaixo.</p></ul>

<ul><pre><code>sudo apt-get update
sudo apt-get install libgsl-dev</code></pre></ul>

<ul><p>Os computadores do prédio O já tem a gsl instalados.</p></ul>
<ul><p>A gsl necessita de flags especiais para a compilação de códigos, entaõ para compilar siga o exemplo</p></ul>

<ul><pre><code>gcc programa.c -lgsl -lgslcblas -lm -static</code></pre></ul>

<ul><p>A última flag é importante caso vá executar algum programa no <a href="https://wiki.if.ufrgs.br/index.php/Cluster">cluster</a> da física.</p></ul>

<h3 id="programas">Programas</h3>

<ul><li><p>Resolução de EDOs Acopladas</p></li></ul>
<ul><p>A vezes na física nos deparamos com sistemas de equações diferencias (EDO) acopladas que queremos resolver. Algumas delas podem ser dificeis de serem resolvidas escrevendo o algoritmo manualmente em um programa de computador, como fazemos em Métodos Computacionais. Podemos então recorrer as funções da bibiblioteca GSl. Abaixo está um exemplo de programa onde é utilizado o método <a href="https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta%E2%80%93Fehlberg_method">Runge-Kutta-Fehlberg</a> para resolver as equações do modelo epidemiológico <a href="https://en.wikipedia.org/wiki/Compartmental_models_in_epidemiology">SIR</a>. Todas informações sobre os métodos de resolução de EDOs podem ser encontradas <a href="https://www.gnu.org/software/gsl/doc/html/ode-initval.html">aqui</a>.</p>
<p><a href="sir_rkf45.c">sir_rkf45.c</a></p></ul>

<ul><li><p>Gerador de Números Aleatórios</p></li></ul>
<ul><p>Em Métodos Computacionais B aprendemos a construir geradores de números aleatórios simples, como os geradores congruentes lineares. Para alguns propósitos esses geradores não são recomendados para uso, quando por exemplo vamos gerar uma grande sequência de números, pois podemos querer gerar mais números que o período e isso comprometeria a qualidade dos dados. A biblioteca GSl dispõe de alguns geradores com períodos grandes, como por exemplo o <a href="https://en.wikipedia.org/wiki/Mersenne_Twister">Mersenne Twister</a> que tem um período longo, de (2<sup>19937</sup> - 1). Abaixo se encontra um exemplo simples de como declarar o gerador e algumas funções básicas para obter valores. As informações sobre os geradores de números aleatórios, tais como mais opções de gerador, podem ser encontradas <a href="https://www.gnu.org/software/gsl/doc/html/rng.html">aqui</a>.</p></ul>
<ul><p><a href="rand_gsl.c">rand_gsl.c</a></p></ul>


<ul><li><p>Números Seguindo Distribuição</p></li></ul>
<ul><p>Pode ser de interesse que precisemos gerar números aleatórios seguindo alguma distribuição, podemos utilizar os geradores de distribuição da GSL. Os geradores de números que seguem uma distribuição necessitam de um número aleatório como semente e então devolvem outro número aleatório seguindo a distribuição desejada (esse também é um assunto abordado em Métodos Computacionais B). Para isso precisaremos inicializar no código o ponteiro relacionado ao gerador aleatório, como abordado na sessão acima, e incluir como argumento da função que gera o número. Abaixo se encontra um programa que utiliza o método <a href="https://en.wikipedia.org/wiki/Box%E2%80%93Muller_transform">Box-Muller</a> para gerar números seguindo a distribuição gaussiana, é possível checar a curva gaussiana fazendo o histograma dos números gerados. Mais informações sobre os geradores e mais exemplos de distribuições disponíveis podem ser encontradas <a href="https://www.gnu.org/software/gsl/doc/html/randist.html">aqui</a>.</p></ul>
<ul><p><a href="gauss_dist.c">gauss_dist.c</a></p></ul>
