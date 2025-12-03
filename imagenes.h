#ifndef IMAGENES_H
#define IMAGENES_H

#include <string>

using namespace std;
#include <opencv2/opencv.hpp>
using namespace cv;

///////////////////////////////////////////////////////////////////
/////////  DEFINICIONES PUBLICAS                     //////////////
///////////////////////////////////////////////////////////////////

#define MAX_VENTANAS 100
// Número máximo de ventanas permitido

// Constantes conocidas en tiempo de compilación

#define DESP_X_HIJO 70
#define DESP_Y_HIJO 50
// Desplazamiento en X e Y de las ventanas hijas respecto de la ventana principal

#define MAX_HIST_IMG 20
// Máximo de acciones guardas en el historial para deshacer/rehacer

///////////////////////////////////////////////////////////////////
/////////  TIPOS DE DATOS PROPIOS                    //////////////
///////////////////////////////////////////////////////////////////

// STRUCT ventana
//    Representa la información asociada a una imagen que está siendo
//    editada actualmente en la aplicación

struct ventana {
    bool usada;             // Indica si se está usando actualmente esta posición
    bool modificada;        // Ha sido modificada después de abrirla o crearla
    string nombre;          // Nombre de la ventana codificada en UTF8
    string nombref;         // Nombre del fichero de imagen codificado en Latin1
    int orden;              // Número de orden entre las ventanas abiertas
    Rect roi;               // Región de interés seleccionada
    Mat img;                // Imagen almacenada en esta posición
    vector<Mat> img_hist;   // Historial de imágenes
    vector<Mat> undo_hist;  // Historial de deshacer
};

// ENUM tipo_herramienta
//    Enumerado con los distintos tipos posibles de herramientas
//    que se pueden usar. Añadir nuevas aquí

enum tipo_herramienta { HER_PUNTO, HER_LINEA, HER_SELECCION, HER_RECTANGULO, HER_ELIPSE, HER_ARCOIRIS, HER_SUAVIZADO };

enum modelo_color {    MC_RGB, // Rojo, Verde, Azul
    MC_HSV,     // Matiz, Saturación, Valor
    MC_HLS,     // Matiz, Luminosidad, Saturación
    MC_XYZ,     // CIE XYZ
    MC_YUV,     // Luma, Crominancia U, Crominancia V
    MC_YCrCb,   // Variante común usada en JPEG/MPEG
    MC_CMYK,    // Cian, Magenta, Amarillo, Negro
};

constexpr tipo_herramienta DEFAULT_HER = HER_PUNTO;
constexpr int DEFAULT_RADIO_PINCEL = 10;
constexpr int DEFAULT_DIFUM_PINCEL = 10;
constexpr int DEFAULT_INCREMENTO_ARCOIRIS = 10;

///////////////////////////////////////////////////////////////////
/////////  VARIABLES PÚBLICAS                        //////////////
///////////////////////////////////////////////////////////////////

extern ventana foto[MAX_VENTANAS];
// El array foto guarda la información de todas las imágenes abiertas
// actualmente o que pueden ser abiertas, hasta un máximo de MAX_VENTANAS

extern tipo_herramienta herr_actual;
// Herramienta que se ha seleccionado actualmente

extern int radio_pincel;
// Radio actual para pintar puntos y líneas

extern Scalar color_pincel;
// Color actual del pincel

extern int difum_pincel;
// Difuminado actual del pincel

extern bool preguntar_guardar;
// Al cerrar una imagen modificada, preguntar si se guarda o no

extern bool callback_inactivo;
// El callback de las ventanas está inactivo por estar ejecutando una herramienta

extern int incremento_arcoiris;
// Incremento del paso de color de la herramienta arcoíris


///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE MANEJO DE VENTANAS           //////////////
///////////////////////////////////////////////////////////////////

void inic_fotos (void);
// Inicializa el array foto, de imágenes abiertas actualmente

void fin_fotos (void);
// Libera las imágenes del array foto

int primera_libre (void);
// Busca la primera entrada libre del array foto

void crear_nueva (int nfoto, int ancho, int alto, Scalar color);
// Crea una nueva entrada, en la posición nfoto, con el ancho y el alto dados,
// de profundidad CV_8U y 3 canales. color indica el color de fondo

void crear_nueva (int nfoto, Mat img);
// Crea una nueva entrada, en la posición nfoto, usando la imagen dada en img

void crear_nueva (int nfoto, string nombre);
// Crea una nueva entrada, en la posición nfoto, leyéndola del archivo nombre.
// Si no se puede leer, no hace nada

void mostrar (int nfoto);
// Muestra la imagen de la entrada nfoto en la ventana correspondiente

void guardar_foto (int nfoto, string nombre= "");
// Guarda en disco la imagen de nfoto, con el nombre dado. Si el nombre
// es "", usa el nombre de la imagen en el array foto

void cerrar_foto (int nfoto, bool destruir_ventana=true);
// Elimina la entrada en la posición nfoto. destruir_ventana indica si debe
// destruirse la ventana de HighGUI (ya que si lo ha hecho el usuario, no
// debe volver a hacerse)

int nombre_a_numero (string nombre);
// Dado un nombre de ventana, busca su número en el array foto.
// Si no lo encuentra devuelve -1

int foto_activa (void);
// Devuelve el número de la ventana de imagen activa (la que esté en primer
// lugar). Si no hay ninguna devuelve -1

int num_fotos (int &usadas, int &modificadas);
// Devuelve el número de fotos que hay abiertas y modificadas actualmente

void activar_callback_fotos (bool activo);
// Activa y desactiva el callback por defecto de las ventanas,
// según el valor del parámetro activo

///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE PROCESAMIENTO DE IMAGENES    //////////////
///////////////////////////////////////////////////////////////////

void invertir (int nfoto, int nres);
// Invierte la imagen contenida en nfoto y la almacena en nres, que será una
// nueva ventana

void copiar_a_nueva (int nfoto, int nres);
// Copiar el ROI de la foto actual a una imagen nueva

void rotar_angulo (Mat imagen, Mat &imgRes, double angulo, double escala=1.0, int modo=0);
// Rota la imagen contenida en imagen, en la cantidad grado (grados
// de 0 a 360) y almacena el resultado en imgRes. La imagen de salida
// siempre está centrada.
// El parámetro modo indica cómo se calcula el tamaño de la imagen resultante:
//    0 = El mismo que la original
//    1 = Tamaño máximo (caber todo), no se pierden los picos de la imagen original
//    2 = Tamaño mínimo (sin bordes), no aparece fondo negro en el resultado

void rotar_exacto (int nfoto, int nres, int grado);
// Rota la imagen contenida en nfoto, en la cantidad 90*grado
// y la almacena en nres. Se trata siempre de una rotación exacta

void ver_brillo_contraste_gamma (int nfoto, double suma, double pro, double gamma,
                           bool guardar=false);
// Modifica la imagen en nfoto, tomando para cada píxel A(x,y) el valor:
// A(x,y)*prod + suma. Si guardar==true se guarda la imagen, y en otro caso
// solo se visualiza el resultado, pero sin guardar

void ver_rojoverdeazul(int nfoto, double r_mul, double r_add,
                       double g_mul, double g_add,
                       double b_mul, double b_add,
                       bool guardar=false);
// Modifica (multiplicar/sumar) cada uno de los canales de forma independiente,
// para poder hacer una transformación de color

void ver_matsatlum (int nfoto, int matiz, double saturacion, double luminosidad,
                   bool guardar=false);
// Ajuste de matiz/saturación/luminosidad

void ver_suavizado (int nfoto, int ntipo, int tamx, int tamy,
                    bool guardar= false);
// Modifica la imagen en nfoto, aplicando un suavizado de tamaño dado. ntipo
// puede ser: 1=GAUSIANO; 2=MEDIA. Si guardar==true se guarda la imagen, y
// en otro caso solo se visualiza el resultado, pero sin guardar

void escala_color(int nfoto, int nres);
// Convertir la imagen de entrada a escala a color del pincel

void ver_pinchar_estirar(int nfoto, int nres, int cx, int cy, double grado, double radio, bool guardar=false);
// Efecto pinchar/estirar

void ver_histograma (int nfoto, int ncanal, int nres);
// Mostrar el histograma de una imagen del ncanal dado (3 = grises)

void perfilado(int nfoto, int radio, double porcentaje, bool guardar=false);
// Mostrar perfilado de una imagen a partir de un radio y un porcentaje

void ver_bajorrelieve(int nfoto, int nres, double angulo, double grado, int tamSobel, int ntextura, bool guardar=false);
// Efecto de bajorrelieve

void media_ponderada (int nf1, int nf2, int nueva, double peso);
// Calcula la media ponderada entre la imagen nf1 y la nf2, según el peso dado,
// y almacena el resultado en la posición nueva. Se aplica la fórmula:
// nueva(x,y):= peso*nf1(x,y)+(1-peso)*nf2(x,y). La imagen nf2 se reescala al
// tamaño de nf1

void ecualizacion_hist(int nfoto, int modo, bool guardar=false);
// Ecualización del histograma

void ajuste_lineal_hist (int nfoto, double pmin, double pmax, bool guardar=false);
// Operación de ajuste lineal del histograma

void convertir_a_modelo (int nfoto, int nres, modelo_color mc);
// Convierte la imagen a un espacio de color específico.
// Genera 3 nuevas ventanas independientes, una para cada canal del modelo elegido

void aplicar_mapa_color(int nfoto, int id_mapa, bool guardar=false);
// Aplica un mapa de color de OpenCV a una imagen (convertir a color falso)

void balance_blancos(int nfoto, int nres);
// Ajuste automático del balance de blancos

void guardar_estado (int nfoto);
// Guarda una copia profunda (clone) de la imagen actual en la pila de 'deshacer'.
// Debe llamarse justo antes de aplicar cualquier modificación destructiva.

void deshacer (int nfoto);
// Recupera el último estado guardado de la imagen (CTRL+Z)

void rehacer (int nfoto);
// Vuelve a aplicar el último cambio deshecho (CTRL+Y)

string Lt1(string cadena);
// Convertir una cadena de UTF8 a Latin1

#endif // IMAGENES_H
