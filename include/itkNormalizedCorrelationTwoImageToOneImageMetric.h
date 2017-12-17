/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkNormalizedCorrelationTwoImageToOneImageMetric_h
#define itkNormalizedCorrelationTwoImageToOneImageMetric_h

#include "itkTwoImageToOneImageMetric.h"
#include "itkCovariantVector.h"
#include "itkPoint.h"


namespace itk
{
/** \class NormalizedCorrelationTwoImageToOneImageMetric
 * \brief Computes similarity between two fixed images and one moving image
 *
 * This metric computes the correlation between pixels in the two fixed images
 * and pixels in the moving image. The spatial correspondance between
 * two fixed images and the moving image is established through a Transform. Pixel values are
 * taken from the fixed images, their positions are mapped to the moving
 * image and result in general in non-grid position on it. Values at these
 * non-grid position of the moving image are interpolated using user-selected
 * Interpolators. The correlation is normalized by the autocorrelations of both
 * the fixed and moving images.
 *
 * \ingroup RegistrationMetrics
 * \ingroup TwoProjectionRegistration
 */
template < typename TFixedImage, typename TMovingImage >
class NormalizedCorrelationTwoImageToOneImageMetric :
    public TwoImageToOneImageMetric< TFixedImage, TMovingImage >
{
public:
  /** Standard class typedefs. */
  typedef NormalizedCorrelationTwoImageToOneImageMetric        Self;
  typedef TwoImageToOneImageMetric<TFixedImage, TMovingImage > Superclass;

  typedef SmartPointer<Self>                                   Pointer;
  typedef SmartPointer<const Self>                             ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(NormalizedCorrelationTwoImageToOneImageMetric, Object);


  /** Types transferred from the base class */
  typedef typename Superclass::RealType                 RealType;
  typedef typename Superclass::TransformType            TransformType;
  typedef typename Superclass::TransformPointer         TransformPointer;
  typedef typename Superclass::TransformParametersType  TransformParametersType;
  typedef typename Superclass::TransformJacobianType    TransformJacobianType;
  typedef typename Superclass::GradientPixelType        GradientPixelType;

  typedef typename Superclass::MeasureType              MeasureType;
  typedef typename Superclass::DerivativeType           DerivativeType;
  typedef typename Superclass::FixedImageType           FixedImageType;
  typedef typename Superclass::MovingImageType          MovingImageType;
  typedef typename Superclass::FixedImageConstPointer   FixedImageConstPointer;
  typedef typename Superclass::MovingImageConstPointer  MovingImageConstPointer;


  /** Get the derivatives of the match measure. */
  void GetDerivative( const TransformParametersType & parameters,
                      DerivativeType & Derivative ) const ITK_OVERRIDE;

  /**  Get the value for single valued optimizers. */
  MeasureType GetValue( const TransformParametersType & parameters ) const ITK_OVERRIDE;

  /**  Get value and derivatives for multiple valued optimizers. */
  void GetValueAndDerivative( const TransformParametersType & parameters,
                              MeasureType& Value, DerivativeType& Derivative ) const ITK_OVERRIDE;

  /** Set/Get SubtractMean boolean. If true, the sample mean is subtracted
   * from the sample values in the cross-correlation formula and
   * typically results in narrower valleys in the cost fucntion.
   * Default value is false. */
  itkSetMacro( SubtractMean, bool );
  itkGetConstReferenceMacro( SubtractMean, bool );
  itkBooleanMacro( SubtractMean );

protected:
  NormalizedCorrelationTwoImageToOneImageMetric();
  ~NormalizedCorrelationTwoImageToOneImageMetric() ITK_OVERRIDE {};
  void PrintSelf(std::ostream& os, Indent indent) const ITK_OVERRIDE;

private:
  NormalizedCorrelationTwoImageToOneImageMetric(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  bool    m_SubtractMean;
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkNormalizedCorrelationTwoImageToOneImageMetric.hxx"
#endif

#endif
