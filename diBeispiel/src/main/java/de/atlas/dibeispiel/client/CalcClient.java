package de.atlas.dibeispiel.client;

import de.atlas.dibeispiel.math.Calculator;
import lombok.AllArgsConstructor;
import org.springframework.stereotype.Component;

@Component
@AllArgsConstructor
public class CalcClient {

    private final Calculator calculator;




    public void go() {
        System.out.println(calculator.add(3,4));
    }
}
