# TP1-Estrutura-de-dados

<h2>1 Introdução</h2>
  
  <p>No ano de 2076 as mega corpora¸c˜oes dominaram o mundo, onde cada uma delas controla de forma
vasta as tecnologias que regem o comportamento da sociedade. Em especial, a corporaçãoo Rellocator
CO. utiliza uma tecnologia denominada Virtual Environment for Relocation Leisure and Autonomous
Behavior (VERLAB). Essa tecnologia ´é responsável por permitir upload e download de consciˆencias na
mega-net (uma internet interplanet´aria).
Atrav´es dos servi¸cos da Rellocator CO., uma pessoa pode fazer upload de sua mente para o VERLAB que age como uma esp´ecie de ambiente virtual na mega-net. Dentro desse ambiente virtual, as
diversas consciˆencias podem interagir, se divertir atrav´es dos mais variados tipos de simula¸c˜oes, e mais
importante, se realocar para outros corpos em diferentes planetas espalhados pelo universo e que foram
colonizados pela ra¸ca humana.
A tecnologia de realoca¸c˜ao de consciˆencias foi o que permitiu que a humanidade se expandisse para
outros planetas de forma eficiente, pois ela permite que cientistas e profissionais das mais diversas ´areas
possam contribuir com solu¸c˜oes para problemas espalhados pelo universo. Para realocar uma consciˆencia
a mesma precisa ser transferida atrav´es da mega-net para um corpo sint´etico, biol´ogico ou rob´otico. O
grande problema quando se trabalha com realoca¸c˜ao de consciˆencias ´e o fato de que hackers que agem de
forma integrada com formas h´ıbridas de Inteligˆencia Artificial conseguem roubar as mesmas enquanto
s˜ao transferidas.
Segundo dados liberados pela Rellocator CO., 27% das consciˆencias que trafegam pela mega-net
s˜ao roubadas e realocadas para corpos rob´oticos escavadores em minas de Composto Z espalhadas em
diversos asteroides e planetas. Uma vez realocada para um robˆo escavador, a consciˆencia ´e reprogramada
para agir como um escravo e sua humanidade ´e completamente perdida. No ano de 2075, por exemplo,
v´arios hackers atuaram durante a cria¸c˜ao de robˆos escravos em diversas expedi¸c˜oes identificadas pelo
codinome Extra¸c˜ao-Z. Para reduzir o ´ındice de roubo de consciˆencias, a Rellocator CO. contratou vocˆe
para implementar um sistema de seguran¸ca, detec¸c˜ao de anomalias, e implementa¸c˜ao de planos de a¸c˜ao,
durante um processo de transferˆencia atrav´es da mega-net.</p>
<br>
<h2>2 Especificações</h2>
<p>
  Para implantar o seu sistema a Rellocator CO. lhe deu acesso a um sub-conjunto de servidores de
transferˆencia da mega-net que atuam utilizando buffers de dados de transferˆencia. O seu sistema deve
executar comandos (planos de a¸c˜ao de distribuição de dados), enviar dados para os buffers dos servidores
de transferˆencia, marcar anomalias nos dados enviados, detectar erros no sistema, e reiniciar toda a
infra-estrutura caso seja necess´ario. Al´em disso, o sistema deve manter um hist´orico das consciˆencias
enviadas, esse hist´orico ´e ´unico e global e pode ser utilizado para conferir as transferˆencias realizadas.
Existem seis comandos que seu controlador pode executar, sendo eles o comando ‘INFO’, ‘WARN’,
‘TRAN’, ‘ERRO’, ‘SEND’, ‘FLUSH’. Cada comando pode ter at´e 3 parˆametros no formato String, como
descritos a seguir.
1
<li>‘INFO S DADOS’: Ao executar este comando, o conte´udo da vari´avel ‘DADOS’ deve ser inserido
no buffer do servidor ‘S’, em forma de uma mensagem (String), com pol´ıtica First in, First out
(FIFO) para transferˆencia na mega-net. Por exemplo, o comando ‘INFO 5 "NIVIO 00010101"’
  corresponde a enviar os dados ‘NIVIO 00010101’ para o servidor 5.</li>
<li>‘WARN S I’: Um comando ‘WARN’ ´e executado pelo controlador central quando ´e detectada
uma tentativa de hacking dos dados. Nesse caso, deve-se remover os dados da posi¸c˜ao ‘I’ do buffer
do servidor ‘S’ e inseri-los na primeira posi¸c˜ao do buffer desse mesmo servidor para antecipar o seu
envio. Por exemplo, o comando ‘WARN 3 7’ corresponde a remover a mensagem que se encontra
  na posi¸c˜ao 7 do buffer da m´aquina 3 e a inserir na primeira posição do mesmo.</li>
  
<li>‘TRAN S1 S2’: Este comando tem como finalidade desabilitar um servidor ‘S1’ quando s˜ao
detectadas poss´ıveis anomalias. Para que isso seja feito de forma a n˜ao perder o conte´udo do buffer
do servidor ‘S1’, deve-se transferir os seus dados para o buffer do servidor ‘S2’. A transferˆencia
deve ocorrer na ordem em que os dados estiverem dispostos em ‘S1’ (Política de remoção FIFO).
Já a inserção deve ser feita no fim do buffer de ‘S2’, ou seja, os dados devem ser inseridos ao fim
dos dados que j´a est˜ao no buffer de ‘S2’. Por fim, deve-se deletar todo o conte´udo do buffer de
‘S1’. Por exemplo, o comando ‘TRAN 2 13’ corresponde a transferir todo o conte´udo do buffer do
  servidor 2 para o buffer do servidor 13 e deletar todo o conte´udo do buffer do servidor 2.</li>
  
<li>‘ERRO S’: A execu¸c˜ao de um comando de ERRO identifica que algo estranho ocorreu na meganet. Quando isso ocorre, deve-se imprimir no terminal a mensagem ‘ERRO S’ e todo o conteúdodo do buffer do servidor ‘S’. Posteriormente, deve-se deletar todo o conte´udo do buffer de ‘S’.</li>
  
<li>‘SEND’: Quando o controlador central executa um comando ‘SEND’, deve-se percorrer os buffers de
todos os servidores enviando os dados da primeira posi¸c˜ao de cada um, e removendo-os do buffer.
Os dados s˜ao enviados para os corpos destino e tamb´em devem ser armazenados no hist´orico de
  consciˆencias enviadas.</li>
  
<li>‘FLUSH’: Ao executar um comando do tipo ‘FLUSH’, deve-se imprimir no terminal o histórico de
consciências na ordem que foram enviadas. Além disso, deve-se também imprimir no terminal, o
conteúdo do buffer de TODOS os servidores (a impress˜ao de um buffer individual deve ser feita
utilizando política FIFO)</li>
<p>
  
<h2>3 Entrada</h2>
<p>
  O executável do seu programa deve receber um argumento de entrada via linha de comando que
representa o nome do arquivo que contém os comandos a serem executados. No arquivo de entrada, a
primeira linha contém a quantidade de servidores que estão disponíveis para você gerenciar. As demais
linhas do arquivo cont´em os comandos descritos na Se¸c˜ao 2. As Strings ‘DATA’ e ‘MSG’ dos comandos da
Seção 2 estarão contidas entre aspas duplas ‘"’ como no exemplo a seguir.
</p>

![image](https://user-images.githubusercontent.com/51410946/133819723-8f175c6c-0f84-424c-b180-5409b54b9c81.png)

<p>Entrada 1: Exemplo de arquivo de entrada que contém a quantidade de m´aquinas dispon´ıveis e todos os
comandos a serem executados, onde os conte´udos das mensagens s˜ao armazenadas entre aspas duplas.</p>

<h2>4 Saída</h2>
<p>
Utilize a saída padrão ‘stdout’/terminal para imprimir todas as informa¸c˜oes. A sa´ıda deve conter a
resposta dos comandos conforme especificado na Se¸c˜ao 2. As mensagens devem ser impressas sem aspas
duplas ‘"’. A seguir ´e apresentado um exemplo de sa´ıda v´alida para entrada apresentada na Seção 3.
</p>

![image](https://user-images.githubusercontent.com/51410946/133820247-b8b44f5a-c6a5-48ec-b57f-32f661b75e24.png)

<p>Saída 1: Exemplo de saída para a entrada apresentada na Seção 3.</p>
<p>
Obs: No apêndice A, ao fim deste documento, é apresentado um exemplo de execução para uma instância
de entrada que contém todos os comandos apresentados
<p/>
