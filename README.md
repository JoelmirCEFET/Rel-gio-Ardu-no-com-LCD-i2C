<h1><strong>&nbsp; &nbsp; &nbsp;Rel&oacute;gio Ardu&iacute;no com LCD i2C</strong></h1>
<p>Esse e um rel&oacute;gio funcional onde ser&aacute; exibido hora e data num visor LCD ligado a um modulo serial i2C.</p>
<h1><strong>&nbsp; &nbsp; &nbsp;Descri&ccedil;&atilde;o </strong></h1>
<p>O projeto tem como intuito funcionar como um rel&oacute;gio digital, que possa mostra as horas de uma forma mais pratica.</p>
<p>&nbsp;</p>
<h1><strong>&nbsp; &nbsp; &nbsp;Pr&eacute;-requisitos </strong></h1>
<p>Tenha em m&atilde;os:</p>
<p>Uma placa&nbsp;Arduino;</p>
<p>Um visor LCD 16 colunas por duas linhas (16&times;2);</p>
<p>m&oacute;dulo RTC;</p>
<p>Um modulo serial que ser&aacute; acoplado ao visor;</p>
<p>Fios conforme sua necessidade;</p>
<h1>&nbsp; &nbsp; &nbsp;<strong>Instala&ccedil;&atilde;o </strong></h1>
<p>O projeto sera montado em uma protoboard e o esquema de instala&ccedil;&atilde;o segue conforme a imagem abaixo:</p>
<h1>&nbsp;</h1>
<p><img src="https://nerdking.net.br/wp-content/uploads/2016/10/Untitled-Sketch_bb-2.png" width="624" height="423" /></p>
<h2><strong>&nbsp; &nbsp; Esquema de liga&ccedil;&atilde;o Ardu&iacute;no RTC LCD i2C</strong></h2>

<p>&nbsp; &nbsp; Depois de montar conforme o esquema vamos a programa&ccedil;&atilde;o, copie e cole o c&oacute;digo abaixo para a IDE do seu Arduino e logo em seguida fa&ccedil;a o upload do programa.</p>

<p>&nbsp;</p>

<p><strong>&nbsp;</strong></p>

<p><br /><br /></p>

<ol>
<li>#include "Wire.h"</li>
<li>#include &lt;LiquidCrystal_I2C.h&gt; //Biblioteca do visor</li>
<li>LCD i2C</li>
<li>#define DS1307_ADDRESS 0x68 // Modulo RTC no endereco</li>
<li>0x68</li>
<li>LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);</li>
<li>// Modulo I2C display no endereco 0x27</li>
<li>byte zero = 0x00;</li>
<li>void setup(){</li>
<li>begin();</li>
<li>backlight(); //Inicia o visor LCD com a luz ligada</li>
<li>begin (16,2);</li>
<li>begin(9600); //Inicia a porta serial</li>
<li>//A linha de comando abaixo serve para que voc&ecirc; possa</li>
<li>confirar a hora e data do seu modulo RTC</li>
<li>// SelecionaDataeHora();</li>
<li>}</li>
<li>void loop()</li>
<li>{</li>
<li>// Le os valores (data e hora) do modulo DS1307</li>
<li>beginTransmission(DS1307_ADDRESS);</li>
<li>write(zero);</li>
<li>endTransmission();</li>
<li>requestFrom(DS1307_ADDRESS, 7);</li>
<li>int segundos = ConverteparaDecimal(Wire.read());</li>
<li>int minutos = ConverteparaDecimal(Wire.read());</li>
<li>int horas = ConverteparaDecimal(Wire.read() &amp;</li>
<li>0b111111);</li>
<li>int diadasemana = ConverteparaDecimal(Wire.read());</li>
<li>int diadomes = ConverteparaDecimal(Wire.read());</li>
<li>int mes = ConverteparaDecimal(Wire.read());</li>
<li>int ano = ConverteparaDecimal(Wire.read());</li>
<li>// Mostra os dados no display</li>
<li>setCursor(0,0);</li>
<li>print(" ");</li>
<li>// Acrescenta o 0 (zero) se a hora for menor do que 10</li>
<li>if (horas &lt;10)</li>
<li>print("0");</li>
<li>print(horas);</li>
<li>print(":");</li>
<li>// Acrescenta o 0 (zero) se minutos for menor do que</li>
<li>10</li>
<li>if (minutos &lt; 10)</li>
<li>print("0");</li>
<li>print(minutos);</li>
<li>print(":");</li>
<li>// Acrescenta o 0 (zero) se minutos for menor do que</li>
<li>10</li>
<li>if (segundos &lt; 10)</li>
<li>print("0");</li>
<li>print(segundos);</li>
<li>setCursor(2,1);</li>
<li>// Mostra o dia da semana</li>
<li>switch(diadasemana)</li>
<li>{</li>
<li>case 0:lcd.print("Dom");</li>
<li>break;</li>
<li>case 1:lcd.print("Seg");</li>
<li>break;</li>
<li>case 2:lcd.print("Ter");</li>
<li>break;</li>
<li>case 3:lcd.print("Qua");</li>
<li>break;</li>
<li>case 4:lcd.print("Qui");</li>
<li>break;</li>
<li>case 5:lcd.print("Sex");</li>
<li>break;</li>
<li>case 6:lcd.print("Sab");</li>
<li>}</li>
<li>setCursor(6,1);</li>
<li>// Acrescenta o 0 (zero) se dia do mes for menor do que</li>
<li>10</li>
<li>if (diadomes &lt; 10)</li>
<li>print("0");</li>
<li>print(diadomes);</li>
<li>print("/");</li>
<li>// Acrescenta o 0 (zero) se mes for menor do que 10</li>
<li>if (mes &lt; 10)</li>
<li>print("0");</li>
<li>print(mes);</li>
<li>print("/");</li>
<li>print(ano);</li>
<li>}</li>
<li>void SelecionaDataeHora() //Seta a data e a hora do</li>
<li>DS1307</li>
<li>{</li>
<li>byte segundos = 10; // Valores de 0 a 59</li>
<li>byte minutos = 05; //Valores de 0 a 59</li>
<li>byte horas = 22; //Valores de 0 a 23</li>
<li>byte diadasemana = 2; //Valores de 0 a 6 - 0=Domingo,</li>
<li>1 = Segunda, etc.</li>
<li>byte diadomes = 25; //Valores de 1 a 31</li>
<li>byte mes = 10; //Valores de 1 a 12</li>
<li>byte ano = 16; //Valores de 0 a 99</li>
<li>beginTransmission(DS1307_ADDRESS);</li>
<li>write(zero); //Stop no CI para que o mesmo possa</li>
<li>receber os dados</li>
<li>//As linhas abaixo escrevem no CI os valores de</li>
<li>//data e hora que foram colocados nas variaveis acima</li>
<li>write(ConverteParaBCD(segundos));</li>
<li>write(ConverteParaBCD(minutos));</li>
<li>write(ConverteParaBCD(horas));</li>
<li>write(ConverteParaBCD(diadasemana));</li>
<li>write(ConverteParaBCD(diadomes));</li>
<li>write(ConverteParaBCD(mes));</li>
<li>write(ConverteParaBCD(ano));</li>
<li>write(zero);</li>
<li>endTransmission();</li>
<li>}</li>
<li>byte ConverteParaBCD(byte val)</li>
<li>{</li>
<li>//Converte o n&uacute;mero de decimal para BCD</li>
<li>return ( (val/10*16) + (val%10) );</li>
<li>}</li>
<li>byte ConverteparaDecimal(byte val)</li>
<li>{</li>
<li>//Converte de BCD para decimal</li>
<li>return ( (val/16*10) + (val%16) );</li>
<li>}</li>
</ol>
<p><br /><br /></p
  <h1><strong>&nbsp; &nbsp; &nbsp; &nbsp;Importante !!</strong></h1>

<p>&nbsp;Observe que a linha 18 do codigo esta comentada e para que voc&ecirc; possa atualizar a data e horas do RTC voc&ecirc; precisa ativar esta linha de comando e alterar conforme sua data e horario atuais nas linhas 87 a 93 depois de atualizar a data e hora desative a linha de comando 18 e fa&ccedil;a novamente o upload do programa. Pois se nao fizer isso toda vez que resetar o arduino a data e hora vao ser aquelas que voc&ecirc; configurou da primeira vez !&nbsp;</p>
<h1><strong>&nbsp; &nbsp; &nbsp;</strong></h1>

<h1><strong>&nbsp; &nbsp; &nbsp;Uso</strong></h1>

<p>&nbsp; E um projeto que pode ser usado como base para outros projetos e ser usado para simplesmente mostrar as horas, em equipamentos, maquinas em industrias que possa monitorar o funcionamento do mesmo.</p>

<p>&nbsp;</p>

<h1><strong>&nbsp; &nbsp; &nbsp;Contribuindo</strong></h1>

<p><a href="https://nerdking.net.br/relogio-arduino-com-lcd-i2c/">https://nerdking.net.br/relogio-arduino-com-lcd-i2c/</a></p>

<p><a href="https://create.arduino.cc/getting-started">https://create.arduino.cc/getting-started</a></p>

<p>Com algumas pesquisas nesses sites me ajudaram a fazer grande parte desse trabalho para mais informa&ccedil;oes de bribioteca como configurar segue o link.&nbsp;</p>
