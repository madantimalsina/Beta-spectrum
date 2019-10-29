/*
 This is the beta spectrum of the tritium for the energy and momentum 
 written by Madan K. Sharma Timalsina for the Experiment and particle 
 physics (PHY739) course by Dr. Juergen Reichenbacher. Here I used the 
 Fermigolden rule to find the expression for the energy and moomentum.

 The expression for the energy of tritium is 
 N(E) = K/c^3 * (18.6 - E)^2 * sqrt(E^2 + 2*E*511)* (E + 511)

The expression for the meomentum of tritium is
N(p) = k * p^2* (18.6 - sqrt(p^2 + 511^2) + 511)^2

Where K is constant, c is spped of light, E is kinetic energy,
        p is momentum, mc^2 = 511 keV, E(T) = Q-value = 18.6 keV/c^2
*/

void betaSpectrum()
{

	    //Canvas
          TCanvas *c = new TCanvas("c","Beta Energy Spectrum",800,500);
          c->SetGrid();
        //Historgam for the beta energy  
          TH1F *h_bEnergy = new TH1F("h_bEnergy", "Beta Energy Spectrum (Tritium)", 200, 0.1, 20.0-0.1);
            h_bEnergy->GetXaxis()->SetTitle("Kinetic Energy [keV]");
            h_bEnergy->GetYaxis()->SetTitle("#Counts");
            h_bEnergy->SetStats(kFALSE);
            //h_bEnergy->SetMaximum(8000000.);
            h_bEnergy->SetMinimum(0.);

        // function for the beta energy ( you can also just use function not making hist)
        // Here E = Q = 18.6 keV/c and I assume  kinetic energy = x, for simplicity 
         //TF1 *fa1 = new TF1("fa1","(18.6-x)*(18.6-x)*(x+511.)*sqrt((x*x)+(2.*x*511.))",0.,20.);
         //Normalize
         TF1 *fa1 = new TF1("fa1","(1/8.0e+06)*(18.6-x)*(18.6-x)*(x+511.)*sqrt((x*x)+(2.*x*511.))",0.,20.);
         //fa1->GetHistogram()->SetTitle("Beta Energy Spectrum (Tritium)");
         //fa1->GetHistogram()->GetYaxis()->SetTitle("#Counts");
         //fa1->GetHistogram()->GetXaxis()->SetTitle("Kinetic Energy [keV]");
         h_bEnergy->Draw();
         fa1->Draw("same");

         TCanvas *c1 = new TCanvas("c1","Beta Momentum Spectrum",800,500);
         c1->SetGrid();

        //Histogram for the beta momentum 
         TH1F *h_bmomentum = new TH1F("h_bmomentum", "Beta Momentum Spectrum (Tritium)", 1500, 0.1, 150.0-0.1);
            h_bmomentum->GetXaxis()->SetTitle("Momentum [keV/c]");
            h_bmomentum->GetYaxis()->SetTitle("#Counts");
            h_bmomentum->SetStats(kFALSE);
            //h_bmomentum->SetMaximum(1000000.);
            h_bmomentum->SetMinimum(0.);

        // function for the beta momentum, 
        // Here E = Q = 18.6 keV/c and I assume  momentum (p) = x, for simplicity   
         //TF1 *fa2 = new TF1("fa2","x*x*(18.6-sqrt(x*x+511*511)+511)*(18.6-sqrt(x*x+511*511)+511)",0.,150.);
         //Normalize
         TF1 *fa2 = new TF1("fa2","(1/1.0e+06)*x*x*(18.6-sqrt(x*x+511*511)+511)*(18.6-sqrt(x*x+511*511)+511)",0.,150.);
         //fa2->GetHistogram()->SetTitle("Beta Momentum Spectrum (Tritium) ");
         //fa2->GetHistogram()->GetYaxis()->SetTitle("#Counts");
         //fa2->GetHistogram()->GetXaxis()->SetTitle("Momentum [keV/c]");
         h_bmomentum->Draw();
         fa2->Draw("Same");
}