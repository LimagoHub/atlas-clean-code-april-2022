package de.atlas.dibeispiel.math;

import org.springframework.stereotype.Component;
import org.springframework.stereotype.Service;

@Service
public class CalculatorImpl implements Calculator{
    @Override
    public double add(double a, double b) {
        return a + b;
    }
}
