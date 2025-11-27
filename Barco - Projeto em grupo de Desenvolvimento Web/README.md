**Barcos de Luxo — Website Completo**

Este repositório reúne o projeto Barcos de Luxo, um site desenvolvido para apresentar e comercializar embarcações de categoria premium — como iates, lanchas e jet skis — priorizando um visual sofisticado, navegação intuitiva e uma experiência de usuário refinada.

O conteúdo inclui todas as páginas, funcionalidades, estilos, scripts e componentes do site final.

---

### Visão Geral

O site oferece uma navegação moderna e exclusiva, com:

* Página inicial com banner dinâmico e destaques
* Catálogo completo com filtros por tipo
* Páginas individuais de cada embarcação
* Sistema de Login e Cadastro em modal
* Mapa interativo utilizando Leaflet.js
* Layout responsivo com Bootstrap 5
* Identidade visual premium com tema claro e escuro
* Componentes reutilizáveis por meio de CSS customizado

---

### Estrutura das Páginas

**1. Página Inicial (index.html)**

* Seção principal com imagem de fundo e botão de ação
* Cards de embarcações em destaque
* Seção “Nossa Filosofia”
* Mapa indicando a localização da loja (Leaflet)
* Menu superior com opção de login

**2. Catálogo (catalogo.html)**

* Filtros por categoria: Iates, Lanchas, Jet Skis e Todos
* Cards com preço, breve descrição e botão de detalhes
* Tema escuro com aspecto premium
* Layout totalmente responsivo

**3. Páginas de Detalhes (ex.: SpiritFerretti88.html)**

* Imagem principal ou galeria
* Especificações técnicas
* Descrição completa
* Botão para contato ou agendamento

---

### Componentes e Funcionalidades

**Modal de Login e Cadastro**
Inclui:

* Login com email e senha
* Cadastro com nome, data de nascimento, CPF, endereço, telefone, email e senha
* Interface organizada em abas (nav-pills)

**Mapa Interativo (Leaflet)**
Arquivo: js/configuracoes.js

* Exibe a localização da loja
* Marcador personalizado
* Zoom e controles ajustáveis

**Estilos**
Localizados na pasta css/:

* bootstrap.min.css
* estilos.css

Inclui:

* Paleta de cores “gold & black”
* Cartões responsivos com sombras
* Fontes Playfair Display e Roboto
* Botões personalizados (btn-gold, btn-outline-gold)

---

### Estrutura do Projeto

```
/
├── index.html
├── catalogo.html
├── SpiritFerretti88.html
├── Intermarine95.html
├── Azimut60.html
├── (outras páginas)
│
├── css/
│   ├── bootstrap.min.css
│   └── estilos.css
│
├── js/
│   ├── bootstrap.bundle.min.js
│   └── configuracoes.js
│
├── imagens/
│   ├── logo2.png
│   ├── Ferretti01.jpg
│   ├── Intermarine01.jpeg
│   ├── Azimut01.jpg
│   ├── (demais imagens)
│
└── README.md
```

---

### Tecnologias Utilizadas

| Tecnologia             | Uso                                   |
| ---------------------- | ------------------------------------- |
| HTML5                  | Estrutura do site                     |
| CSS3 / CSS customizado | Estilização                           |
| Bootstrap 5            | Responsividade e componentes          |
| Leaflet.js             | Mapa interativo                       |
| FontAwesome            | Ícones                                |
| Google Fonts           | Tipografia                            |
| JavaScript             | Comportamento e configurações do mapa |

---

### Funcionalidades Concluídas

* Layout totalmente responsivo
* Navegação completa entre páginas
* Catálogo com filtros funcionais
* Modal de login e cadastro com boa experiência de uso
* Mapa carregado automaticamente na página inicial
* Componentes reutilizáveis
* Identidade visual consistente
