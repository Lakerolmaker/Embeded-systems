

Input(weight);
Input(height);
Input(bmi);

Input(fitness) //(1 = underweight, 2 = fit, 3 = obese);

bmi = ( weight ) / ( height * height );

if( bmi < 18 ){
    fitness = 1;
}else if( bmi > 18 && bmi < 25 ){
    fitness = 2;
}else{
    fitness = 3;
}


Output(fitness);
