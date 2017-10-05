# exampleIoT
Hung: 
							
					READ DATA

	FillRect(100, 290, 65,35, White); 				// pump
	Guitext_text_35pts(100, 290,"ON",Black,Black); 	// pump

	FillRect(100, 210, 65,35, White); 				// fan
	Guitext_text_35pts(100, 210,"ON",Black,Black); 	// fan

	FillRect(385, 215, 100,75, White); 				// temp
	Guitext_text_72pts(390, 215,c0,Black,Black);	// temp

	FillRect(596, 215, 100,75, White); //humidity	// humidity
	Guitext_text_72pts(600, 215,c1,Black,Black);	// humidity

	FillRect(230, 235, 100,75, White);				// PH
	Guitext_text_72pts(230, 235,c2,Black,Black);	// PH

	FillRect(20, 380, 120,30, White); 				// lamp1
	Guitext_text_27pts(20, 380,c3,Black,Black);		// lamp1

	FillRect(205, 380, 120,30, White); 				// lamp2
	Guitext_text_27pts(205, 380,c4,Black,Black);	// lamp2

	FillRect(390, 380, 120,30, White); 				// lamp3
	Guitext_text_27pts(390, 380,c5,Black,Black);	// lamp3

	Guitext_text_72pts(580, 370,(signed char*)"1203",Black,Blue); //PPM

					WRITE DATA

	FillRect(50, 430, 120,35, White); 				// lamp1
	Guitext_text_27pts(50, 430,c6,Black,Black);		// lamp1
	Guitext_text_27pts(95, 430,"%",Black,Black);	// lamp1

	FillRect(235, 430, 120,35, White); 				// lamp2
	Guitext_text_27pts(235, 430,c7,Black,Black);	// lamp2
	Guitext_text_27pts(280, 430,"%",Black,Black);	// lamp2

	FillRect(420, 430, 120,35, White); 				// lamp3
	Guitext_text_27pts(420, 430,c8,Black,Black); 	// lamp3
	Guitext_text_27pts(465, 430,"%",Black,Black);	// lamp3
