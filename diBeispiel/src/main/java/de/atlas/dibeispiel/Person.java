package de.atlas.dibeispiel;

import lombok.Builder;
import lombok.Data;

@Data
@Builder
public class Person {

    private String anrede;
    private String vorname;
    private String nachname;

    public Person setVorname(String vorname) {
        this.vorname = vorname;
        return this;
    }
}
