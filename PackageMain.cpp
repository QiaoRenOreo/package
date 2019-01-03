#include <iostream>

class Package //base
{
	protected://to be inherited, these values have to be protected
		std::string name;
		std::string address;
		std::string city;
		std::string state;
		int SenderZIPCode;//ZIPcode for the sender
		int ReceiverZIPCode;//ZIPcode for the receiver
		double weight;//weight of the package, in kg
		double CostPerKg;//cost per kg to ship the package

	public:
		Package(std::string nameval, //build a constructor to initialize the values
				std::string addressval,
				std::string cityval,
				std::string stateval,
				int SenderZIPVal,
				int ReceiverZIP,
				double WeightVal,
				double CostPerKgVal):

				name(nameval),
				address(addressval),
				city(cityval),
				state(stateval),
				SenderZIPCode(SenderZIPVal),
				ReceiverZIPCode(ReceiverZIP)

				{
					if (WeightVal>0) 	//Ensure that the weight contain a positive value
					{
						weight=WeightVal;
					}
					else
					{
						std::cout<<"the weight value should be positive"<<std::endl;
						weight=0;//dummy value. Because without the dummy value, the program can not proceed.
					}

					if (CostPerKgVal>0)  //Ensure that the CostPerKg contain a positive value
					{
						CostPerKg= CostPerKgVal;
					}
					else
					{
						std::cout<<"the CostPerKg value should be positive"<<std::endl;
						CostPerKg=0;//dummy value
					}
				};

		double calculateCost() //returns a double indicating the cost associated with shipping the package
		{
			double ShippingCost;
			ShippingCost=weight*CostPerKg;// multiplying the weight by the cost per kg
			return ShippingCost;
		}
};



class TwoDayPackage : public Package //inherit the functionality of base class Package
{
	protected:
		double FlatFee;// two-day-delivery service needs to change the FlatFee
		double TracTraceCost;
	public:
		TwoDayPackage(std::string nameval,
				std::string addressval,
				std::string cityval,
				std::string stateval,
				int SenderZIPVal,
				int ReceiverZIP,
				double WeightVal,
				double CostPerKgVal,
				double FlatFeeValue,
				double TracTraceCostVal) :

				Package(nameval,
						addressval,
						cityval,
						stateval,
						SenderZIPVal,
						ReceiverZIP,
						WeightVal,
						CostPerKgVal),
						FlatFee(FlatFeeValue),
						TracTraceCost(TracTraceCostVal)
				{
				};

		double calculateCost()//computes the shipping cost by adding the flat fee
		{
			double ShippingCost;
			ShippingCost=weight*CostPerKg+FlatFee;
			std::cout<<"ShippingCost of TwoDayPackage : "<<ShippingCost<<" dollars"<<std::endl;
			return ShippingCost;
		}

		double CostTractAndTrace()//calculate the cost of track and trace
		{
			double TracTraceShippingCost;
			TracTraceShippingCost=weight*CostPerKg+FlatFee+TracTraceCost;//=The original shipping cost +  the ¡°TrackAndTrace¡± service cost.
			std::cout<<"ShippingCost of TwoDayPackage with TracknTrace: "<<TracTraceShippingCost<<" dollars"<<std::endl;
			return TracTraceShippingCost;
		}
};



class OvernightPackage: public Package
{
	protected:
		double AdditionalFee;//OvernightPackage charges an additional fee per kg
	public:

		OvernightPackage(std::string nameval,
						std::string addressval,
						std::string cityval,
						std::string stateval,
						int SenderZIPVal,
						int ReceiverZIP,
						double WeightVal,
						double CostPerKgVal,
						double AdditionalFeeVal) :

						Package(nameval,
								addressval,
								cityval,
								stateval,
								SenderZIPVal,
								ReceiverZIP,
								WeightVal,
								CostPerKgVal),
								AdditionalFee(AdditionalFeeVal)
							{
							};

		double calculateCost() //redefine member function calculateCost
		{
			double ShippingCost;
			ShippingCost=weight*(CostPerKg+AdditionalFee);
			std::cout<<"ShippingCost of OvernightPackage : "<<ShippingCost<<" dollars"<<std::endl;
			return ShippingCost;
		}
};



int main() //a test program
{

	Package myPackage //creates an objects of the type Package
		("Bob","EndlessStraat 20","Enschede","ABC State", 1234,5678,60.2,12.5);

	TwoDayPackage My2DayPackage //creates an objects of the type TwoDayPackage
		("Bob","EndlessStraat 20","Enschede","ABC State", 1234,5678,60.2,12.5, 3.2,4.5);

	OvernightPackage MyOvernightPackage //creates an objects of the type TwoDayPackage
		("Bob","EndlessStraat 20","Enschede","ABC State", 1234,5678,60.2,12.5, 4.7);

	MyOvernightPackage.calculateCost();//tests its member function calculateCost.
	My2DayPackage.calculateCost();//tests its member function calculateCost.
	My2DayPackage.CostTractAndTrace();//tests its member function CostTractAndTrace
}




