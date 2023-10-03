void pintarFondo(std::string es_color) {

    std::string string_color = "color " + es_color;
    const char* color = string_color.c_str();

    if (es_color == "70") { // Blanco
        system(color);
    }
    else if (es_color == "07") { // Negro
        system(color);
    }
    else if (es_color == "17") { // Azul
        system(color);
    }
    else if (es_color == "27") { // Verde
        system(color);
    }
    else if (es_color == "37") { // Aguamarina
        system(color);
    }
    else if (es_color == "47") { // Rojo
        system(color);
    }
    else if (es_color == "57") { // Purpura
        system(color);
    }
    else if (es_color == "67") { // Amarillo
        system(color);
    }
    else if (es_color == "87") { // Gris
        system(color);
    }
    else if (es_color == "97") { // Azul claro
        system(color);
    }
    else if (es_color == "a7") { // Verde claro
        system(color);
    }
    else if (es_color == "b7") { // Aguamarina claro
        system(color);
    }
    else if (es_color == "c7") { // Rojo claro
        system(color);
    }
    else if (es_color == "d7") { // Purpura claro
        system(color);
    }
    else if (es_color == "e7") { // Amarillo claro
        system(color);
    }
    else {
        std::cout << "El valor ingresado para colorear no es reconocible.";
    }
}