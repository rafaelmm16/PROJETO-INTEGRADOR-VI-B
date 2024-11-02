const int ledVerde = 11;
const int ledAmarelo = 12;
const int ledVermelho = 13;
const int botaoPedestre = 2;

const unsigned long debounceDelay = 50;

enum EstadoSemaforo {
  VERDE,
  AMARELO,
  VERMELHO
};

EstadoSemaforo estadoAtual = VERDE;
unsigned long tempoMudancaEstado = 0;

// Debounce
static bool estadoBotao = HIGH;
static unsigned long tempoUltimaMudancaBotao = 0;
bool pedestreApertado = false;


void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(botaoPedestre, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  unsigned long tempoAtual = millis();

  // Debounce do botão
  bool leituraBotao = digitalRead(botaoPedestre);
  if (leituraBotao != estadoBotao) {
    tempoUltimaMudancaBotao = tempoAtual;
    estadoBotao = leituraBotao;
  }

  if (estadoBotao == LOW && (tempoAtual - tempoUltimaMudancaBotao) > debounceDelay) {
    pedestreApertado = true;
    Serial.println("Botao de pedestre pressionado");
  }

  // Lógica do semáforo
  switch (estadoAtual) {
    case VERDE:
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVermelho, LOW);
      if (tempoAtual - tempoMudancaEstado >= 5000) {
        estadoAtual = AMARELO;
        tempoMudancaEstado = tempoAtual;
      }
      break;

    case AMARELO:
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, HIGH);
      digitalWrite(ledVermelho, LOW);
      if (tempoAtual - tempoMudancaEstado >= 2000) {
        estadoAtual = VERMELHO;
        tempoMudancaEstado = tempoAtual;
      }
      break;

    case VERMELHO:
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVermelho, HIGH);
      if (tempoAtual - tempoMudancaEstado >= 5000) {
        if (pedestreApertado) {
          // Aciona a sequência do pedestre APENAS se o botão foi pressionado
          delay(5000); // Mantém o vermelho por mais 5 segundos para o pedestre
          pedestreApertado = false; // Reseta a flag
        }
        estadoAtual = VERDE; // Volta para o verde após o vermelho (e a sequência do pedestre, se acionada)
        tempoMudancaEstado = tempoAtual;
      }
      break;
  }
}