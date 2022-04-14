package de.atlas.dibeispiel;

import de.atlas.dibeispiel.client.CalcClient;
import lombok.AllArgsConstructor;
import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;


@Component
@AllArgsConstructor
public class MyCommandlineRunner implements CommandLineRunner {

    private final CalcClient client;

    @Override
    public void run(String... args) throws Exception {

        Person p = Person.builder()
                .vorname("John")
                .nachname("Doe")
                .build()

        client.go();
    }
}
